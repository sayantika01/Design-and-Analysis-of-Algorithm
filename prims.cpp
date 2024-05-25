#include<bits/stdc++.h>
using namespace std;
const int MAX_VERT=100;
int minKey(int vertices, int key[],bool mstSet[]){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<vertices;i++){
        if(!mstSet[i] && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void printMST(int parent[],int adjMatrix[MAX_VERT][MAX_VERT],int vertices){
    cout<<"EDGE\t \t WEIGHT\t\n";
    for(int i=1;i<vertices;i++){
        cout<<parent[i]<<"- "<<i<<" \t "<<adjMatrix[i][parent[i]]<<" \n";
    }
}
void prims(int adjMatrix[MAX_VERT][MAX_VERT], int vertices){
    int key[MAX_VERT];
    int parent[MAX_VERT];
    bool mstSet[MAX_VERT]={false};
    for(int i=0;i<vertices;i++){
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<vertices-1;count++){
        int u=minKey(vertices,key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<vertices;v++){
            if(adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v]<key[v]){
                parent[v]=u;
                key[v]=adjMatrix[u][v];
            }
        }
    }
    printMST(parent,adjMatrix, vertices);
}
int main(){
    int vertex, edge;
    cout<<"Enter the number of vertices: ";
    cin>>vertex;
    cout<<"Enter the number of edges: ";
    cin>>edge;
    int adjMatrix[MAX_VERT][MAX_VERT]={0};
    cout<<"Enter the edges with their weight (u,v,w):  "<<endl;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjMatrix[u][v]=w;
        adjMatrix[v][u]=w;
    }
    prims(adjMatrix, vertex);
    return 0;
}