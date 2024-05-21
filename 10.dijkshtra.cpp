#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100; // Maximum number of vertices in the graph

// Function to find the vertex with the minimum distance value, from the set of vertices not yet processed
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to implement Dijkstra's single source shortest path algorithm for a graph represented using an adjacency matrix
void dijkstra(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES]; 
    bool visited[MAX_VERTICES] = {false}; 

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; //self loop

    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited, vertices);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            // Update dist[v] only if is not in visited, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex\t Distance from Source" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix representation of the graph

    cout << "Enter the edges with their weights (u v w):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // For undirected graph; remove this line for directed graph
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    dijkstra(adjMatrix, startVertex, vertices);

    return 0;
}
