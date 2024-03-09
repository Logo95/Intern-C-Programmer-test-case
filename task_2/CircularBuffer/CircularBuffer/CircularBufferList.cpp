// CircularBufferList.cpp

#include "CircularBufferList.h"

template <typename T>
CircularBufferList<T>::CircularBufferList(size_t capacity) : head(nullptr), tail(nullptr), size(0), capacity(capacity-1) {}

template <typename T>
void CircularBufferList<T>::push(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (size == 0) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
    if (size > capacity) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

template <typename T>
T CircularBufferList<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }

    T value = head->data;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;

    return value;
}

template <typename T>
bool CircularBufferList<T>::empty() const {
    return size == 0;
}

template <typename T>
size_t CircularBufferList<T>::getSize() const {
    return size;
}

template <typename T>
size_t CircularBufferList<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void CircularBufferList<T>::view() const {
    if (empty()) {
        std::cout << "Buffer is empty" << std::endl;
        return;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    delete temp;
}

template class CircularBufferList<int>;
template class CircularBufferList<char>;