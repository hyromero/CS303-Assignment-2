// Hiram Romero
// Assignment 2

#ifndef STACK_H
#define STACK_H

#include <vector> // Vector library
#include <iostream> // input/output

using namespace std; // to avoid using std::

class Stack {
private:
    vector<int> data; // Vector used to hold stack elements

public:
    void push(int value); // Function to add a value to the top of the stack
    void pop(); // Function to remove the top value from the stack
    bool empty() const; // Function to check if the stack is empty
    int top() const; // Function to get the top value without removing it
    double average() const; // Function to calculate the average of stack values
    void printStack() const; // Function to print all elements in the stack
};

#endif // STACK_H
