#include <QCoreApplication>
#include <QSemaphore>
#include <QWaitCondition>
#include <QThread>
#include <QMutex>
#include <stdio.h>
const int data_size=1000;
const int buffer_size=80;
int buffer[buffer_size];
#if 0
QSemaphore free_bytes(buffer_size);
QSemaphore used_bytes(0);

class producer : public QThread
{
protected:
    void run() override
    {
        for(int i=0;i<data_size;i++)
        {
            free_bytes.acquire();
            buffer[i%buffer_size]=i%buffer_size;
            used_bytes.release();
        }
    }
};

class consumer : public QThread
{
protected:
    void run() override
    {
        for(int i=0;i<data_size;i++)
        {
            used_bytes.acquire();
            fprintf(stderr,"%d",buffer[i%buffer_size]);
            if(i%16==0&&i!=0)
            {
                fprintf(stderr,"\n");
            }
            free_bytes.release();
        }
        fprintf(stderr,"\n");
    }
};
#else
QWaitCondition buffer_empty;
QWaitCondition buffer_full;
QMutex mutex;
int free_bytes=0;
int read_index=0;
class producer : public QThread
{
protected:
    void run() override
    {
        QThread::sleep(1);
        for(int i=0;i<data_size;i++)
        {
            mutex.lock();
            if(free_bytes==buffer_size)
            {
                buffer_empty.wait(&mutex);
            }
            buffer[i%buffer_size]=i%buffer_size;
            free_bytes++;
            buffer_full.wakeAll();
            mutex.unlock();
        }
    }
};

class consumer : public QThread
{
protected:
    void run() override
    {
        QThread::sleep(1);
        for(int i=0;i<data_size;i++)
        {
            mutex.lock();
            if(free_bytes==0)
            {
                buffer_full.wait(&mutex);
            }
            printf("%p::[%d]=%d\n",currentThreadId(),read_index,buffer[read_index]);
            read_index=(++read_index)%buffer_size;
            free_bytes--;
            buffer_empty.wakeAll();
            mutex.unlock();
        }
        printf("\n");
    }
};
#endif

int main(int argc, char *argv[])
{
    qDebug()<<"start";
    QCoreApplication a(argc, argv);
    producer my_producer1,my_producer2;
    consumer my_consumer1,my_consumer2;
    my_producer1.start();
    my_producer2.start();
    my_consumer1.start();
    my_consumer2.start();
    my_producer1.wait();
    my_producer2.wait();
    my_consumer1.wait();
    my_consumer2.wait();
    return 0;
}
