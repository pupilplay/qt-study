#ifndef WORKER_THREAD_H
#define WORKER_THREAD_H

#include <QThread>
#include <QDebug>

class worker_thread : public QThread
{
    Q_OBJECT
public:
    worker_thread();
protected:
    void run() override;
};

#endif // WORKER_THREAD_H
