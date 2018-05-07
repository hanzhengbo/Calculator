//
// Created by 韩正博 on 18/4/18.
//

#ifndef MYCALCULATOR_STACK_H
#define MYCALCULATOR_STACK_H

#include <iostream>

using namespace std;

const int maxlen = 100;

template<typename ElementType>
class Stack {
public:
    Stack();

    bool isEmpty();

    bool isFull();

    bool push(ElementType x);

    bool pop();

    ElementType getTopElement();

private:
    int count;
    ElementType data[maxlen];
};

template<typename ElementType>
Stack<ElementType>::Stack() {
    count = 0;
}

template<typename ElementType>
bool Stack<ElementType>::isEmpty() {
    if (count == 0)
        return true;
    return false;
}

template<typename ElementType>
bool Stack<ElementType>::isFull() {
    if (count == maxlen)
        return true;
    return false;
}

template<typename ElementType>
bool Stack<ElementType>::pop() {
    if (!isEmpty()) {
        count--;
        return true;
    }
    return false;
}

template<typename ElementType>
bool Stack<ElementType>::push(ElementType x) {
    if (!isFull()) {
        data[count++] = x;
        return true;
    }
    return false;
}

template<typename ElementType>
ElementType Stack<ElementType>::getTopElement() {
    ElementType x;
    if (!isEmpty()) {
        x = data[count - 1];
        return x;
    }
    return NULL;
}

#endif //MYCALCULATOR_STACK_H
