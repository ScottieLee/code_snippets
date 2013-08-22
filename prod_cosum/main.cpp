#include <QtCore/QCoreApplication>
#include "circular_buffer.h"
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    circular_buffer buffer(100);
    producer pro(buffer);
    consumer con(buffer);
    con.start();
    sleep(10);
    pro.start();

    return a.exec();
}
