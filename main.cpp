//Hiram Romero
//Assignment 2

#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
};

void printList(Node* n) {
    while (n != NULL) {
        cout << n->Value << endl;
        n = n->Next;
    }
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;

    // Call the printList function to output the list
    printList(head);

    // Clean up memory (optional but good practice)
    delete head;
    delete second;
    delete third;

    return 0;
}
