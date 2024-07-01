#include "mystack.h"
#include<QDebug>
template<typename T>
MyStack<T>::MyStack(int capacity) : capacity(capacity), topIndex(-1) {
    stackArray = new T[capacity];
    summ=0;
}
template<typename T>
MyStack<T>::MyStack() : capacity(0), topIndex(-1) {
    stackArray = nullptr;
    summ=0;
}
template<typename T>
MyStack<T>::~MyStack() {
    delete[] stackArray;
}

template<typename T>
void MyStack<T>::push(const T& value) {
    if (isFull()) {
        throw std::overflow_error("Stack overflow");
    }
    stackArray[++topIndex] = value;
    summ+=value;

}

template<typename T>
void MyStack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow");
    }
    summ-=stackArray[topIndex];
    --topIndex;
    //capacity--;
}

template<typename T>
T MyStack<T>::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return stackArray[topIndex];
}

template<typename T>
bool MyStack<T>::isEmpty() const {
    return topIndex == -1;
}

template<typename T>
bool MyStack<T>::isFull() const {
    return topIndex == capacity - 1;
}

template<typename T>
void MyStack<T>::removeTwoDigitNumbers() {
    MyStack<int> tempStack(capacity);  // Temporary stack to hold non-two-digit numbers

    while (!isEmpty()) {
        int value = top();
        qDebug()<<value<<" ";
        pop();
        if (value < 10 || value > 99) {
            tempStack.push(value);
        }
    }
    int n=0;
    // Move elements back to the original stack
    while (!tempStack.isEmpty()) {
        push(tempStack.top());
        n++;
        tempStack.pop();
    }
    capacity=n;
}

template<typename T>
QString MyStack<T>::toQString() const {
    QString result;
    for (int i = topIndex; i >= 0; --i) {
        result = QString::number(stackArray[i])+result;
        if (i > 0) {
            result = " "+result;
        }
    }
    return result;
}

template<typename T>
int MyStack<T>::Summa() const{
    return summ;
}

template<typename T>
int MyStack<T>::FindMax() const{
    int max=stackArray[0];
    for(int i=0;i<=topIndex;i++)
    {
        if(max<stackArray[i])
            max=stackArray[i];
    }
    return max;
}
// Explicit instantiation
template class MyStack<int>;
