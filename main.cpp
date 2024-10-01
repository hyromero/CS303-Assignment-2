//Hiram Romero
//Assignment 2
#include <iostream> //Used for input and output
#include "LinkedList.h" // Linked List Header file
#include "Stack.h" // Stack Header file

using namespace std;

void displayMenu() { // Displays the menu for the user
    cout << "Select an option:" << endl;
    cout << "1. Push Front - Linked List" << endl;
    cout << "2. Push Back - Linked List" << endl;
    cout << "3. Pop Front - Linked List" << endl;
    cout << "4. Pop Back - Linked List" << endl;
    cout << "5. Insert at Index - Linked List" << endl;
    cout << "6. Remove at Index - Linked List" << endl;
    cout << "7. Find Item - Linked List" << endl;
    cout << "8. Stack Operations" << endl;
    cout << "9. Exit" << endl;
}

void displayStackMenu() { // Displays the Stack menu for the user when they select the stack operations
    cout << "Select stack option:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Check if Empty" << endl;
    cout << "4. Top of Stack" << endl;
    cout << "5. Average of Stack" << endl;
    cout << "6. Print Stack" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    LinkedList list; // Creates a linked list object
    list.printList(); // Prints the current list 0-10

    Stack stack; // Create a stack object
    int choice, value, index; // Declare index here

    while (true) { // Loops until the user chooses to exit
        displayMenu();
        cin >> choice; // take user input for choice using switch statement

        switch (choice) { // Switch statement for the menu options
            case 1:
                cout << "Enter value to push front: ";
                cin >> value;
                list.push_front(value); //pushes the user input to front of list
                list.printList(); //prints the updated list
                break;
            case 2:
                cout << "Enter value to push back: ";
                cin >> value;
                list.push_back(value); //pushes the user input to back of list
                list.printList(); // prints the updated list
                break;
            case 3:
                list.pop_front(); // deletes the item from the front of the list
                list.printList(); // prints the updated list
                break;
            case 4:
                list.pop_back(); //deletes the item from the back of the list
                list.printList(); // prints the updated list
                break;
            case 5:
                cout << "Enter index and value to insert: ";
                cin >> index >> value; // takes user input for index and value to insert
                list.insert(index, value); //inserts the value
                list.printList(); //prints updated list
                break;
            case 6:
                cout << "Enter index to remove: ";
                cin >> index; // takes user input for index to remove
                if (list.remove(index)) { //if index exists , removes it
                    cout << "Removed item at index " << index << endl;
                } else { //if not, prints error message
                    cout << "Failed. Index out of bounds." << endl;
                }
                list.printList(); //prints updated list
                break;
            case 7:
                cout << "Enter value to find: ";
                cin >> value; // takes user input for value to find
                index = list.find(value); //finds the index of the value
                if (index == list.size()) { //if value isnt found, sends error message
                    cout << "Item not found. Index: " << index << endl;
                } else { //if it is, prints out the vlaue and index associated with it
                    cout << "Index of " << value << ": " << index << endl;
                }
                break;
            case 8: {
                int stackChoice; //option for stack options
                while (true) { //while selected, prints menu option for user
                    displayStackMenu(); //displays the stack menu options
                    cin >> stackChoice; //takes input

                    switch (stackChoice) { //switch statement for stack options
                        case 1:
                            cout << "Enter value to push onto stack: ";
                            cin >> value;
                            stack.push(value); //adds/pushes value onto stack
                            break;
                        case 2:
                            stack.pop(); //removes the top value from the stack
                            break;
                        case 3:
                            cout << (stack.empty() ? "Stack is empty." : "Stack is not empty.") << endl; //outpus if stack is empty or not
                            break;
                        case 4:
                            cout << "Top of stack: " << stack.top() << endl; //outputs the value at the top of the stack
                            break;
                        case 5:
                            cout << "Average of stack: " << stack.average() << endl;// calculates the average of the stack
                            break;
                        case 6:
                            stack.printStack(); //prints stack to show user current stack
                            break;
                        case 7:
                            break; // Exits the menu loop
                        default:
                            cout << "Invalid choice, try again." << endl;
                            break;
                    }
                    if (stackChoice == 7) break;
                }
                break;
            }
            case 9:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    }

    return 0;
}

