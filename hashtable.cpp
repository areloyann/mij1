#include <iostream>
#include <vector>
#include <list>
#include <utility> // For std::pair
using namespace std;

class HashTable {
private:
    // Hash Table will be an array of lists (for chaining)
    vector<list<pair<int, string>>> table;
    int capacity; // Size of the hash table

    // Hash function: to map a key to an index
    int hash(int key) {
        return key % capacity;
    }

public:
    // Constructor: Initializes hash table with a given size
    HashTable(int size) {
        capacity = size;
        table.resize(capacity);
    }

    // Insert a key-value pair
    void insert(int key, string value) {
        int index = hash(key);
        table[index].push_back(make_pair(key, value)); // Chaining: add to the list at the index
    }

    // Search for a value by key
    string search(int key) {
        int index = hash(key);
        // Traverse the list at that index
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return the value associated with the key
            }
        }
        return "Not found"; // If the key doesn't exist
    }

    // Delete a key-value pair
    void remove(int key) {
        int index = hash(key);
        // Traverse the list at that index
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it); // Remove the pair
                return;
            }
        }
        cout << "Key not found." << endl;
    }

    // Display the entire hash table
    void display() {
        for (int i = 0; i < capacity; ++i) {
            if (!table[i].empty()) {
                cout << "Bucket " << i << ": ";
                for (auto& pair : table[i]) {
                    cout << "(" << pair.first << ", " << pair.second << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table with 10 buckets

    ht.insert(1, "One");
    ht.insert(12, "Twelve");
    ht.insert(22, "Twenty-Two");
    ht.insert(3, "Three");

    ht.display(); // Display the hash table

    cout << "Search for key 12: " << ht.search(12) << endl; // Should return "Twelve"
    cout << "Search for key 5: " << ht.search(5) << endl;   // Should return "Not found"

    ht.remove(12); // Remove key 12
    ht.display();   // Display the updated hash table

    return 0;
}
