
#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>
#include <QString>

template<typename T>
class MyStack {
private:
    T* stackArray;   // Pointer to the array that holds the stack elements
    int capacity;    // Maximum capacity of the stack
    int topIndex;    // Index of the top element in the stack
    int summ;

public:
    MyStack();
    MyStack(int capacity);
    ~MyStack();

    void push(const T& value);
    void pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void removeTwoDigitNumbers();
    QString toQString() const; // New method to convert stack to QString
    int Summa() const;
    int FindMax() const;
};

#endif // MYSTACK_H
