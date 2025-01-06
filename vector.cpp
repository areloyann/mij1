#include <iostream> 
using namespace std; 
 
class Vector { 
private: 
    int* data; 
    size_t size; 
    size_t capacity; 
 
    void resize() { 
        capacity *= 2; 
        int* newData = new int[capacity]; 
        for (size_t i = 0; i < size; ++i) { 
            newData[i] = data[i]; 
        } 
        delete[] data; 
        data = newData; 
    } 
 
public: 
    Vector() : data(new int[2]), size(0), capacity(2) {} 
 
    ~Vector() { 
        delete[] data; 
    } 
 
    void push_back(int value) { 
        if (size == capacity) { 
            resize(); 
        } 
        data[size++] = value; 
    } 
 
    void display() const { 
        for (size_t i = 0; i < size; ++i) { 
            cout << data[i] << " "; 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    Vector vec; 
    vec.push_back(10); 
    vec.push_back(20); 
    vec.push_back(30); 
    vec.display(); // Output: 10 20 30 
 
    return 0; 
}
