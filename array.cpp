#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;
    int capacity;

public:
    // Constructor
    Array(int cap = 4) : size(0), capacity(cap) {
        data = new int[capacity];
    }

    // Destructor
    ~Array() {
        delete[] data;
    }

    // Add an element
    void add(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    // Get an element
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return -1;
        }
        return data[index];
    }

    // Print the array
    void print() {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Array arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.print(); // Output: 10 20 30
    cout << "Element at index 1: " << arr.get(1) << endl; // Output: 20
    return 0;
}
