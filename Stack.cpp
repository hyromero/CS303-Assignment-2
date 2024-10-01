// Hiram Romero
// Assignment 2

#include "Stack.h" // Include the Stack header

void Stack::push(int value) {   // Function to add a value to the top of the stack
    data.push_back(value); // Add the value to the end of the vector
}

void Stack::pop() {    // Function to remove the top value from the stack
    if (empty()) {
        cout << "Stack is empty. Cannot remove." << endl; // Notifies the user if the stack is empty
    } else {
        data.pop_back(); // removes the last value in the vector
    }
}

bool Stack::empty() const {
    // function that checks if the stack is empty
    return data.empty(); // returns true if the vector is empty
}

int Stack::top() const { // function to get to the top value of the stack
    if (empty()) {
        cout << "Stack is empty." << endl; // prints if the stack is empty
        return -1; // Return -1 or throw an exception to indicate error
    }
    return data.back(); // returns the last value in the vector
}

double Stack::average() const { //function that caclulates average

    if (empty()) {
        cout << "Stack is empty. Cannot calculate average." << endl; // Notify if empty
        return 0.0; //
    }
    double sum = 0; // sum is initialized to double zero
    for (int value : data) {
        sum += value; // add together the values
    }
    return sum / data.size(); // this returns the average
}

void Stack::printStack() const {
    // function that allows user to see stack
    cout << "Current Stack: ";
    for (int value : data) {
        cout << value << " "; // prints the stack
    }
    cout << endl;
}
