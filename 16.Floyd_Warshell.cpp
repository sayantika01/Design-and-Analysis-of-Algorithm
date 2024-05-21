#include <iostream>
#include <iomanip>
using namespace std;

#define INF 99999
#define MAX 100

void printSolution(int dist[MAX][MAX], int V) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}

void floydWarshall(int graph[MAX][MAX], int V) {
    int dist[MAX][MAX];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix (enter " << INF << " for INF):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (i == j) graph[i][j] = 0; // Distance to self is 0
        }
    }

    floydWarshall(graph, V);

    return 0;
}
