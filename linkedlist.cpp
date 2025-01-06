#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int value) : data(value), next(nullptr) {} 
}; 
 
class LinkedList { 
private: 
    Node* head; 
 
public: 
    LinkedList() : head(nullptr) {} 
 
    ~LinkedList() { 
        Node* temp; 
        while (head) { 
            temp = head; 
            head = head->next; 
            delete temp; 
        } 
    } 
 
    void append(int value) { 
        Node* newNode = new Node(value); 
        if (!head) { 
            head = newNode; 
        } else { 
            Node* temp = head; 
            while (temp->next) { 
                temp = temp->next; 
            } 
            temp->next = newNode; 
        } 
    } 
 
    void display() const { 
        Node* temp = head; 
        while (temp) { 
            cout << temp->data << " -> "; 
            temp = temp->next; 
        } 
        cout << "nullptr" << endl; 
    } 
}; 
 
int main() { 
    LinkedList ll; 
    ll.append(5); 
    ll.append(2); 
    ll.append(4); 
    ll.display(); 
 
    return 0; 
}
