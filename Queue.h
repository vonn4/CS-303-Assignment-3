#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();
    void push(const T& value);
    void pop();
    T front() const;
    size_t size() const;
    bool empty() const;
    void move_to_rear();

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* frontNode;
    Node* rearNode;
    size_t queueSize;
};

// Constructor
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

// Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// Push function
template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    queueSize++;
}

// Pop function
template <typename T>
void Queue<T>::pop() {
    if (empty()) throw std::out_of_range("Queue is empty");
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    queueSize--;
    if (empty()) rearNode = nullptr;
}

// Front function
template <typename T>
T Queue<T>::front() const {
    if (empty()) throw std::out_of_range("Queue is empty");
    return frontNode->data;
}

// Size function
template <typename T>
size_t Queue<T>::size() const {
    return queueSize;
}

// Empty function
template <typename T>
bool Queue<T>::empty() const {
    return queueSize == 0;
}

// Move front to rear function
template <typename T>
void Queue<T>::move_to_rear() {
    if (size() > 1) {
        T frontElement = front();
        pop();
        push(frontElement);
    }
}

#endif // QUEUE_H
