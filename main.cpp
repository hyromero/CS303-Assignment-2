#include <iostream>
#include "LinkedList.h"

using namespace std; // Add using namespace std here

void displayMenu() {
    cout << "Select an option:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Pop Front" << endl;
    cout << "4. Pop Back" << endl;
    cout << "5. Insert at Index" << endl;
    cout << "6. Remove at Index" << endl;
    cout << "7. Find Item" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    LinkedList list;
    list.printList();

    int choice, value, index;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push front: ";
                cin >> value;
                list.push_front(value);
                list.printList();
                break;
            case 2:
                cout << "Enter value to push back: ";
                cin >> value;
                list.push_back(value);
                list.printList();
                break;
            case 3:
                list.pop_front();
                list.printList();
                break;
            case 4:
                list.pop_back();
                list.printList();
                break;
            case 5:
                cout << "Enter index and value to insert: ";
                cin >> index >> value;
                list.insert(index, value);
                list.printList();
                break;
            case 6:
                cout << "Enter index to remove: ";
                cin >> index;
                if (list.remove(index)) {
                    cout << "Removed item at index " << index << endl;
                } else {
                    cout << "Failed to remove item; index out of bounds." << endl;
                }
                list.printList();
                break;
            case 7:
                cout << "Enter value to find: ";
                cin >> value;
                index = list.find(value);
                if (index == list.size()) {
                    cout << "Item not found. Index: " << index << endl;
                } else {
                    cout << "Index of " << value << ": " << index << endl;
                }
                break;
            case 8:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    return 0;
}

