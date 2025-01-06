#include <iostream>
using namespace std;

class Stack {
private:
    int data[10]; // Fixed-size array for the stack
    int top;      // Index of the top element

public:
    // Constructor
    Stack() : top(-1) {}

    // Push an element onto the stack
    void push(int value) {
        if (top >= 9) { // Check for stack overflow
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        data[++top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) { // Check for stack underflow
            cout << "Stack underflow! Returning -1 as default value." << endl;
            return -1;
        }
        return data[top--];
    }

    // Peek at the top element without removing it
    int peek() {
        if (top == -1) {
            cout << "Stack is empty! Returning -1 as default value." << endl;
            return -1;
        }
        return data[top];
    }

    // Display the stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); // Output: Stack elements (top to bottom): 30 20 10

    cout << "Top element: " << stack.peek() << endl; // Output: Top element: 30

    cout << "Popped element: " << stack.pop() << endl; // Output: Popped element: 30
    stack.display(); // Output: Stack elements (top to bottom): 20 10

    stack.pop();
    stack.pop();
    stack.pop(); // Trying to pop from an empty stack
    stack.display(); // Output: Stack is empty!

    return 0;
}
