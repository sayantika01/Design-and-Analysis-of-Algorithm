#include<bits/stdc++.h>
using namespace std;
const int MAX_VERT=100;
int minDist(int dist[],bool visited[],int vertices){
    int min=INT_MAX,min_index;
    for(int i=0;i<vertices;i++){
        if(!visited[i] && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void dijkshtra(int adjMatrix[MAX_VERT][MAX_VERT],int src, int vertices){
    int dist[MAX_VERT];
    bool visited[MAX_VERT]={false};
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    for(int i=0;i<=vertices;i++){
        int u=minDist(dist,visited,vertices);
        visited[u]=true;
        for(int v=0;v<=vertices;v++){
            if(adjMatrix[u][v] && !visited[v] && dist[u]!=INT_MAX && dist[u]+adjMatrix[u][v]<dist[v]){
                dist[v]=dist[u]+adjMatrix[u][v];
            }
        }
    }
    cout<<"  Vertices \t Distance from the source\n";
    for(int i=0;i<vertices;i++){
        cout<<i<<" \t \t \t "<<dist[i]<<endl;
    }
}
int main(){
    int vertices, edges;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    int adjMatrix[MAX_VERT][MAX_VERT]={0};
    cout<<"Enter the edges with their weight (u,v,w) : "<<endl;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjMatrix[u][v]=w;
        adjMatrix[v][u]=w;
    }
    int start;
    cout<<"Enter the starting vertex: ";
    cin>>start;
    dijkshtra(adjMatrix, start, vertices);
    return 0;
}