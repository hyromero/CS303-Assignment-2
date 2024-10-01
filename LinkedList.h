// Hiram Romero
// Assignment 2

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std; // so we dont have to use std::

class Node {
public:
    int Value; // Enterd value stored in the node
    Node* Next; // Pointer to the next node in the list
};

class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list
    size_t num_items; // Count of items in the list

public:
    LinkedList(); // Constructor to initialize the linked list
    ~LinkedList(); // Destructor to clean up the linked list
    void push_front(int value); // Function used to add a value at the front
    void push_back(int value); // Function used to add a value at the back
    void pop_front(); //Function to remove the value at the front
    void pop_back(); // Function to remove the value at the back
    bool empty() const; // Function to check if the list is empty
    void printList() const; //Function to print the contents of the list
    void insert(size_t index, int value); // Function to insert a value at a specific index
    bool remove(size_t index); // Method to remove a value at a specific index
    size_t find(int value); // Method to find the index of a value in the list
    size_t size() const; // Method to return the number of items in the list
};

#endif // LINKEDLIST_H
