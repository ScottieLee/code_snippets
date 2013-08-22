#include "circular_buffer.h"
#include <iostream>
namespace CircularBuffer{

circular_buffer::circular_buffer(int len):d_bufferUsed(0), d_bufferLeft(len)
{
    d_buffer = new node[len];
    //Make it circular
    for (int v = 0; v < len-1; v++){
        d_buffer[v].next = &d_buffer[v+1];
    }
    d_buffer[len-1].next = &d_buffer[0];
    d_read_ptr = d_buffer;
    d_write_ptr = d_buffer;
}

void circular_buffer::put(int data){
    std::cerr << "putting.." << std::endl;
    d_bufferLeft.acquire(); // -1
    d_write_ptr->data = data;
    d_write_ptr = d_write_ptr->next;
    d_bufferUsed.release(); // +1
    std::cerr << "putting done." << std::endl;
}

int circular_buffer::get(){
    std::cerr << "getting.." << std::endl;
    d_bufferUsed.acquire(); // -1
    int data = d_read_ptr->data;
    d_read_ptr = d_read_ptr->next;
    d_bufferLeft.release(); // +1
    std::cerr << "getting done." << std::endl;
    return data;
}

circular_buffer::~circular_buffer()
{
    delete[] d_buffer;
}

}//endnamespace
