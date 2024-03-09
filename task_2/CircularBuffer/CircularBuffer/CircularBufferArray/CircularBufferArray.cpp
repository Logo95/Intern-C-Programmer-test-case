// CircularBufferArray.cpp

#include "CircularBufferArray.h"

template <typename T>
CircularBufferArray<T>::CircularBufferArray(size_t size) : size(size), head(0), tail(0), full(false) {
    buffer.resize(size);
}

template <typename T>
void CircularBufferArray<T>::push(T value) {
    buffer[head] = value;
    head = (head + 1) % size;
    if (head == tail) {
        full = true;
        tail = (tail + 1) % size;
    }
}

template <typename T>
T CircularBufferArray<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }

    full = false;
    T value = buffer[tail];
    tail = (tail + 1) % size;
    return value;
}

template <typename T>
bool CircularBufferArray<T>::empty() const {
    return !full && (head == tail);
}

template <typename T>
bool CircularBufferArray<T>::isFull() const {
    return full;
}

template <typename T>
void CircularBufferArray<T>::view() const {
    if (empty()) {
        std::cout << "Buffer is empty" << std::endl;
        return;
    }
    size_t tmp = tail;
    while (tmp != head) {
        std::cout << buffer[tmp] << " ";
        tmp = (tmp + 1) % size;
    }
}

template class CircularBufferArray<int>;