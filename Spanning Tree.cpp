#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum spanning tree in a graph
void findMinimumSpanningTree(int graph[][int V], int V) {
    // Array to store the parent of each vertex in the minimum spanning tree
    int parent[V];
    
    // Array to store the key value of each vertex
    int key[V];
    
    // Array to store whether a vertex is included in the minimum spanning tree
    int mstSet[V];
    
    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    
    // The first vertex is always the root of the minimum spanning tree
    key[0] = 0;
    parent[0] = -1;
    
    // Find the minimum spanning tree
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum key value that is not yet included in the minimum spanning tree
        int minKey = INT_MAX;
        int minIndex;
        
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        
        // Include the selected vertex in the minimum spanning tree
        mstSet[minIndex] = 1;
        
        // Update the key values and parent array of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[minIndex][v] && mstSet[v] == 0 && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }
    
    // Print the minimum spanning tree
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int V = 5;
	int graph[][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
     // Number of vertices in the graph
    
    // Find the minimum spanning tree in the graph
    findMinimumSpanningTree(graph, V);
    
    return 0;
}
