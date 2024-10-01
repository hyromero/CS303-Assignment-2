#include "LinkedList.h"

using namespace std; // Add using namespace std here

LinkedList::LinkedList() : head(nullptr), tail(nullptr), num_items(0) {
    for (int i = 0; i <= 10; ++i) {
        push_back(i);
    }
}

LinkedList::~LinkedList() {
    while (!empty()) {
        pop_front();
    }
}

void LinkedList::push_front(int value) {
    Node* newNode = new Node();
    newNode->Value = value;
    newNode->Next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    num_items++;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node();
    newNode->Value = value;
    newNode->Next = nullptr;
    if (tail) {
        tail->Next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    num_items++;
}

void LinkedList::pop_front() {
    if (empty()) {
        cout << "List is empty, cannot pop front." << endl;
        return;
    }
    Node* temp = head;
    head = head->Next;
    delete temp;
    num_items--;
    if (empty()) {
        tail = nullptr;
    }
}

void LinkedList::pop_back() {
    if (empty()) {
        cout << "List is empty, cannot pop back." << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->Next != tail) {
            current = current->Next;
        }
        delete tail;
        tail = current;
        tail->Next = nullptr;
    }
    num_items--;
}

bool LinkedList::empty() const {
    return num_items == 0;
}

void LinkedList::printList() const {
    Node* current = head;
    cout << "Current List: ";
    while (current != nullptr) {
        cout << current->Value << " ";
        current = current->Next;
    }
    cout << endl;
}

void LinkedList::insert(size_t index, int value) {
    if (index >= num_items) {
        push_back(value);
        return;
    }
    if (index == 0) {
        push_front(value);
        return;
    }
    Node* newNode = new Node();
    newNode->Value = value;

    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->Next;
    }
    newNode->Next = current->Next;
    current->Next = newNode;

    if (newNode->Next == nullptr) {
        tail = newNode;
    }

    num_items++;
}

bool LinkedList::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->Next;
    }
    Node* toDelete = current->Next;
    current->Next = toDelete->Next;

    if (toDelete == tail) {
        tail = current;
    }

    delete toDelete;
    num_items--;
    return true;
}

size_t LinkedList::find(int value) {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->Value == value) {
            return index;
        }
        current = current->Next;
        index++;
    }
    return num_items;
}

size_t LinkedList::size() const {
    return num_items;
}
