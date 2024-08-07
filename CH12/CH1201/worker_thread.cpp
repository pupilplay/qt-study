#include "worker_thread.h"

worker_thread::worker_thread()
{
    return;
}

void worker_thread::run()
{
    while(true)
    {
        for(int i=0;i<10;i++)
        {
            qDebug()<<i<<' '<<i<<' '<<i<<' '<<i<<' '<<i<<' '<<i<<' '<<i;
        }
    }
}
