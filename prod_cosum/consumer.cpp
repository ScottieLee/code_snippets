#include "consumer.h"
#include <iostream>
consumer::consumer(circular_buffer& buffer, QObject *parent) :
    QThread(parent), d_buffer(buffer)
{
}

void consumer::run()
{
    while(true){
        sleep(1);
        std::cerr << "Get element: " << d_buffer.get() << std::endl;
    }
}
