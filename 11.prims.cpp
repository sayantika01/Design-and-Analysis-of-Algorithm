#include<bits/stdc++.h>
using namespace std;
const int MAX_VERT=100;
int minKey(int key[],bool mstSet[],int vertices){
    int min=INT_MAX, min_index;

    for(int v=0;v<vertices;v++){
        if(!mstSet[v] && key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}
void printMst(int parent[], int adjMatrix[MAX_VERT][MAX_VERT],int vertices){
    cout<<"Edge \t Weight\t\n";
    for(int i=1;i<vertices;i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<adjMatrix[i][parent[i]]<<" \n";
    }
}
void prim(int adjMatrix[MAX_VERT][MAX_VERT],int vertices){
    int parent[MAX_VERT];
    int key[MAX_VERT];
    bool mstSet[MAX_VERT]={false};

    for(int i=0;i<vertices;i++){
        key[i]=INT_MAX;
    }

    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<vertices-1; count++){
        int u=minKey(key,mstSet,vertices);
        mstSet[u]=true;

        for(int v=0;v<vertices;v++){
            if(adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v]<key[v]){
                parent[v]=u;
                key[v]=adjMatrix[u][v];
            }
        }
    }
    printMst(parent, adjMatrix,vertices);
}

int main() {
    int v, e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    int adjMatrix[MAX_VERT][MAX_VERT]={0};
    cout<<"Enter the edges with their weights(u v w):"<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjMatrix[u][v]=w;
        adjMatrix[v][u]=w;
    }
    prim(adjMatrix,v);
    return 0;
}