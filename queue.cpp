#include <iostream>
using namespace std;

class Queue {
private:
    int* data;      // Dynamic array for queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum capacity of the queue
    int size;       // Current number of elements in the queue

public:
    // Constructor
    Queue(int cap = 10) {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] data;
    }

    // Enqueue: Add an element to the rear
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // Circular increment
        data[rear] = value;
        size++;
    }

    // Dequeue: Remove an element from the front
    int dequeue() {
        if (size == 0) {
            cout << "Queue underflow! Returning -1 as default value." << endl;
            return -1;
        }
        int value = data[front];
        front = (front + 1) % capacity;  // Circular increment
        size--;
        return value;
    }

    // Display the queue elements
    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << data[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: Queue elements: 10 20 30

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl; // Output: Dequeued: 10
    q.display(); // Output: Queue elements: 20 30

    // Add more elements
    q.enqueue(40);
    q.enqueue(50);
    q.display(); // Output: Queue elements: 20 30 40 50

    return 0;
}
