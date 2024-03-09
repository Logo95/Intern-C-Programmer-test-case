// CircularBufferList.h

#pragma once
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularBufferList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
    size_t capacity;

public:
    CircularBufferList(size_t capacity);
    void push(T value);
    T pop();
    bool empty() const;
    size_t getSize() const;
    size_t getCapacity() const;
    void view() const;
};