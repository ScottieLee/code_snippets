#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include "circular_buffer.h"

using namespace CircularBuffer;

class consumer : public QThread
{
    Q_OBJECT
private:
    void run();
    circular_buffer& d_buffer;
public:
    explicit consumer(circular_buffer& buffer, QObject *parent = 0);

signals:

public slots:

};

#endif // CONSUMER_H
