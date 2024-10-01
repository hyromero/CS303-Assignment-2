#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std; // Add using namespace std here

class Node {
public:
    int Value;
    Node* Next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    size_t num_items;

public:
    LinkedList();
    ~LinkedList();
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    bool empty() const;
    void printList() const;
    void insert(size_t index, int value);
    bool remove(size_t index);
    size_t find(int value);
    size_t size() const;
};

#endif // LINKEDLIST_H
