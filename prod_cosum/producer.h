#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include "circular_buffer.h"

using namespace CircularBuffer;

class producer : public QThread
{
    Q_OBJECT
private:
    CircularBuffer::circular_buffer& d_buffer;
    void run();
public:
    explicit producer(CircularBuffer::circular_buffer& buffer, QObject *parent = 0);

signals:

public slots:

};

#endif // PRODUCER_H
