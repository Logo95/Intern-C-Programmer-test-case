// CircularBufferArray.h

#pragma once
#include <iostream>
#include <vector>

template <typename T>
class CircularBufferArray {
private:
    std::vector<T> buffer;
    size_t size;
    size_t head;
    size_t tail;
    bool full;

public:
    CircularBufferArray(size_t size);
    void push(T value);
    T pop();
    bool empty() const;
    bool isFull() const;
    void view() const;
};