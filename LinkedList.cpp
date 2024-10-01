// Hiram Romero
// Assignment 2

#include "LinkedList.h" // Includes the heasder file

using namespace std; //for convenience of not using std::

LinkedList::LinkedList() : head(nullptr), tail(nullptr), num_items(0) { // Constructor initializes an empty linked list and populates it with values 0 to 10
    for (int i = 0; i <= 10; ++i) {
        push_back(i); // Add each value to the back of the linked list
    }
}

LinkedList::~LinkedList() {
    // Destructor cleans up the linked list by removing all nodes
    while (!empty()) {
        pop_front(); // This removes the front node until the list is empty
    }
}

void LinkedList::push_front(int value) { // function that adds a new node with the entered value to the front of the linked list
    Node* newNode = new Node(); // Creates the new node
    newNode->Value = value; // Set the node's value to the entered value
    newNode->Next = head; // Point the new node to the current head
    head = newNode; // Update head to the new node
    if (tail == nullptr) {
        tail = newNode; // If the list was empty, update tail to the new node
    }
    num_items++; // Increments count of items in the list
}

void LinkedList::push_back(int value) { //function that adds a new node with the given value to the back of the linked list
    Node* newNode = new Node(); // Creates a new node
    newNode->Value = value; // Set the node's value to the entered value
    newNode->Next = nullptr; // New node will be the last, so its Next is nullptr
    if (tail) {
        tail->Next = newNode; // If list is not empty, link the current tail to the new node
    } else {
        head = newNode; // If list is empty, new node is now set to the head
    }
    tail = newNode; // Updates tail to the new node
    num_items++; // Increments count of items in the list
}

void LinkedList::pop_front() {// Function that removes the node at the front of the linked list

    if (empty()) {
        cout << "List is empty, cannot pop front." << endl; // Notifies the user if the list is empty
        return;
    }
    Node* temp = head; // This emporarily stores the current head
    head = head->Next; // Move head to the next node
    delete temp; // Delete the old head
    num_items--; // Decrements the count of items
    if (empty()) {
        tail = nullptr; // If list is now empty, set tail to nullptr
    }
}

void LinkedList::pop_back() { //function that removes node from back of list

    if (empty()) {
        cout << "List is empty, cannot pop back." << endl; // Tells user if list is empty
        return;
    }
    if (head == tail) { // If there's only one node
        delete head; // Delete the only node
        head = tail = nullptr; // Set both head and tail to nullptr
    } else {
        Node* current = head; // Starts at the head
        while (current->Next != tail) { // Moves to the second to last node
            current = current->Next;
        }
        delete tail; // Deletes the last node
        tail = current; // Update tail to the second-to-last node
        tail->Next = nullptr; // Set the new tail's Next to nullptr
    }
    num_items--; // Decrement the count of items to be even with change
}

bool LinkedList::empty() const { //bool function for if linked list is empty
    return num_items == 0; // Checsk if the number of items is zero
}

void LinkedList::printList() const {
    // Prints the values of the linked list
    Node* current = head; // Starts at the head then prints out the list
    cout << "Current List: ";
    while (current != nullptr) {
        cout << current->Value << " "; // Print the current node's value
        current = current->Next; // Moves to the next node
    }
    cout << endl; // End the line after printing the list
}

void LinkedList::insert(size_t index, int value) {
    // Inserts a new value at a specified index in the linked list
    if (index >= num_items) { // If index is out of bounds, add to the back
        push_back(value);
        return;
    }
    if (index == 0) { // If inserting at the front
        push_front(value);
        return;
    }
    Node* newNode = new Node(); // Creates a new node
    newNode->Value = value; // Set the new node's value

    Node* current = head; // Starts at the head
    for (size_t i = 0; i < index - 1; i++) { // moves to node before the ente4red index
        current = current->Next;
    }
    newNode->Next = current->Next; // Link new node to the next node
    current->Next = newNode; // Link the previous node to the new node

    if (newNode->Next == nullptr) {
        tail = newNode; // Updates tail if new node is added at the end
    }

    num_items++; // Increment the count of items
}

bool LinkedList::remove(size_t index) {
    // Removes the node at the specified index from the linked list
    if (index >= num_items) return false; // Return false if index is out of bounds
    if (index == 0) { // If removing the front node
        pop_front();
        return true; // Indicate success
    }

    Node* current = head; // Start at the head
    for (size_t i = 0; i < index - 1; i++) { // go to the node before the index
        current = current->Next;
    }
    Node* toDelete = current->Next; // Get the node to delete
    current->Next = toDelete->Next; // the node to delete

    if (toDelete == tail) {
        tail = current; // Update tail if the last node is deleted
    }

    delete toDelete; // Delete the target node
    num_items--; // Decrement the count of items
    return true; // Indicate success
}

size_t LinkedList::find(int value) {
    // Finds the index of a value in the linked list
    Node* current = head; // Start at the head
    size_t index = 0; // Initialize index to 0
    while (current != nullptr) { // go through the list
        if (current->Value == value) {
            return index; // returns the index if the value was found
        }
        current = current->Next; // Moves to the next node
        index++; //incerements the index
    }
    return num_items; // returns  size if value not found
}

size_t LinkedList::size() const {
    // Returns the number of items in the linked list
    return num_items; // Return the count of items
}
