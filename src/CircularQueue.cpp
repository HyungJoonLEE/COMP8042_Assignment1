#include "../include/CircularQueue.h"


/**
 * Constructs a circular queue with a specified capacity.
 *
 * Initializes a circular queue with the given capacity, creating an empty queue.
 *
 * @param capacity The maximum number of elements the queue can hold.
 */
template<typename T>
CircularQueue<T>::CircularQueue(int capacity) {
    buffer = std::vector<T>();
    this->capacity = capacity;
    frontIndex = 0;
    rearIndex = 0;
    currentSize = 0;
}


/**
 * Constructs an empty circular queue with a capacity of 0.
 *
 * Initializes an empty circular queue with a capacity of 0.
 * The queue will not be able to store any elements until its capacity is set explicitly.
 */
template<typename T>
CircularQueue<T>::CircularQueue(): capacity(0), frontIndex(0), rearIndex(0), currentSize(0) {
    buffer = std::vector<T>();
}


/**
 * Checks if the circular queue is empty.
 *
 * @return True if the circular queue is empty, false otherwise.
 */
template<typename T>
bool CircularQueue<T>::isEmpty() const {
    return currentSize == 0;
}


/**
 * Checks if the circular queue is full.
 *
 * @return True if the circular queue is full, false otherwise.
 */
template<typename T>
bool CircularQueue<T>::isFull() const {
    return currentSize == capacity;
}


/**
 * Returns the number of elements in the circular queue.
 *
 * @return The number of elements currently in the circular queue.
 */
template<typename T>
size_t CircularQueue<T>::size() const {
    return currentSize;
}


/**
 * Enqueues an element into the circular queue.
 *
 * Adds the specified element to the rear of the circular queue if it's not full.
 * If the queue is full, no elements will be added.
 *
 * @param element The element to be enqueued.
 */
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


/**
 * Returns a reference to the front element of the circular queue.
 *
 * Retrieves a reference to the element at the front of the circular queue without removing it.
 * It is assumed that the queue is not empty when this function is called.
 *
 * @return A reference to the front element of the circular queue.
 */
template<typename T>
T &CircularQueue<T>::front() {
    return this->buffer.at(frontIndex);
}


/**
 * Returns a constant reference to the front element of the circular queue.
 *
 * Retrieves a constant reference to the element at the front of the circular queue without removing it.
 * It is assumed that the queue is not empty when this function is called.
 *
 * @return A constant reference to the front element of the circular queue.
 */
template<typename T>
const T &CircularQueue<T>::front() const {
    return this->buffer.at(frontIndex);
}


