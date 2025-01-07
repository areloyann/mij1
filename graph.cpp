#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;       // Number of vertices
    int** adjMatrix;    // Adjacency matrix

public:
    // Constructor
    Graph(int vert) {
        vertices = vert;
        adjMatrix = new int* [vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices]();
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Add an edge to the graph
    void addEdge(int u, int v, bool isDirected = false) {
        adjMatrix[u][v] = 1; // Add edge from u to v
        if (!isDirected) {
            adjMatrix[v][u] = 1; // For undirected graph
        }
    }

    // Display the adjacency matrix
    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices

    g.addEdge(0, 1); // Add edge between 0 and 1
    g.addEdge(0, 2); // Add edge between 0 and 2
    g.addEdge(1, 2); // Add edge between 1 and 2
    g.addEdge(2, 3); // Add edge between 2 and 3

    g.display(); // Display the adjacency matrix

    return 0;
}
