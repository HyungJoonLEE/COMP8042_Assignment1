#include "../include/CircularQueue.h"

template<typename T>
CircularQueue<T>::CircularQueue(int capacity) {
    buffer = std::vector<T>();
    this->capacity = capacity;
    frontIndex = 0;
    rearIndex = 0;
    currentSize = 0;
}

template<typename T>
CircularQueue<T>::CircularQueue(): capacity(0), frontIndex(0), rearIndex(0), currentSize(0) {
    buffer = std::vector<T>();
}

template<typename T>
bool CircularQueue<T>::isEmpty() const {
    if (currentSize == 0) {
        return true;
    }
    return false;
}

template<typename T>
bool CircularQueue<T>::isFull() const {
    if (currentSize == capacity) {
        return true;
    }
    return false;
}

template<typename T>
size_t CircularQueue<T>::size() const {
    return currentSize;
}

template<typename T>
void CircularQueue<T>::enqueue(const T &element) {
    buffer.push_back(element);
    currentSize++;
    rearIndex++;
}

template<typename T>
void CircularQueue<T>::dequeue() {
    currentSize--;
    frontIndex++;
}

template<typename T>
T &CircularQueue<T>::front() {
    return buffer.at(frontIndex);
}

template<typename T>
const T &CircularQueue<T>::front() const {
    return buffer.at(frontIndex);
}


