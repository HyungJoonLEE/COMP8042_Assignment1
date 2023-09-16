#include "../include/Stack.h"


template<typename T>
Stack<T>::Stack() {
    buffer = std::vector<T>();
    currentSize = 0;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    if (currentSize == 0) {
        return true;
    }
    else return false;
}

template<typename T>
size_t Stack<T>::size() const {
    return currentSize;
}

template<typename T>
void Stack<T>::push(const T &element) {
    buffer.push_back(element);
    currentSize++;
}

template<typename T>
void Stack<T>::pop() {
    buffer.pop_back();
    currentSize--;
}

template<typename T>
T &Stack<T>::top() {
    return buffer.back();
}

template<typename T>
const T &Stack<T>::top() const {
    return buffer.back();
}

