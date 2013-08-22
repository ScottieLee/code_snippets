#include "producer.h"

producer::producer(circular_buffer& buffer, QObject *parent) :
    QThread(parent),d_buffer(buffer)
{
}

void producer::run()
{
    int i = 0;
    while(true){
        sleep(1);
        d_buffer.put(++i);
    }
}
