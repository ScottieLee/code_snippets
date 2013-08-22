#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <QSemaphore>

namespace CircularBuffer{
struct Node;
typedef struct Node{
    Node* next;
    int   data;
} node;
class circular_buffer
{
private:
    node* d_buffer;
    node* d_read_ptr;
    node* d_write_ptr;
    QSemaphore d_bufferUsed;
    QSemaphore d_bufferLeft;
    circular_buffer(const circular_buffer& rhs);
    circular_buffer& operator = (circular_buffer& rhs);
public:
    explicit circular_buffer(int len);
    ~circular_buffer();
    void put(int data);
    int get();
};


}
#endif // CIRCULAR_BUFFER_H
