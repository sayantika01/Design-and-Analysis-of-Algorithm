#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src;
    int dest;
    int weight;
};
struct Graph{
    int v; //no. of vertices;
    int e; //no.of edges;
    struct Edge* edge;
};
struct Graph* createGraph(int v,int e){
    struct Graph* graph=new Graph;
    graph->v=v;
    graph->e=e;
    graph->edge= new Edge[e];
    return graph;
};
void print(int v, int dist[]){
    cout<<"Vertices \t Distance from the source"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" \t \t "<<dist[i]<<endl;
    }
}
void bellman(struct Graph* graph, int src){
    int v=graph->v;
    int e=graph->e;
    int dist[v];

    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    for(int i=1;i<=v-1;i++){
        for(int j=0;j<e;j++){
            int u= graph->edge[j].src;
            int v= graph->edge[j].dest;
            int w=graph->edge[j].weight;

            if(dist[u]!= INT_MAX && dist[u]+ w < dist[v]){
                dist[v]= dist[u] + w;
            }
        }
    }
    // for negative edges check
    for(int i=0;i<e;i++){
        int u=graph->edge[i].src;
        int v= graph->edge[i]. dest;
        int w= graph->edge[i].weight;

        if(dist[u]!=INT_MAX && dist[u]+ w < dist[v]){
            cout<<"There is a negative weight of an edge !!"<<endl;
            return;
        }
    }
    print (v, dist);
}
int main (){
    int v;
    cout<<"Enter the number of vertices: ";
    cin>> v;
    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    struct Graph* graph = createGraph(v,e);
    cout<<"Enter the edges with their weights (src, dest, weight): "<<endl;
    
    for(int i=0;i<e;i++){
        cin>>graph->edge[i].src>> graph->edge[i].dest>> graph->edge[i].weight;
    }
    int src;
    cout<<"Enter the source vertex: ";
    cin>>src;

    bellman(graph, src);
    return 0;
}