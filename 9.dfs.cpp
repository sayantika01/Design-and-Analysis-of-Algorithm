#include<bits/stdc++.h>
using namespace std;
void dfs(int start, list<int>* adjList, bool* visited){
    stack<int> s;
    s.push(start);
    visited[start]=true;

    while(!s.empty()){
        int node=s.top();
        s.pop();
        cout<<node<<" ";

        for(int neighbour: adjList[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                s.push(neighbour);
            }
        }
    }
}
int main(){
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;

    list<int>* adjList=new list<int>[v];
    bool* visited=new bool[v];

    cout<<"Enter the edges: "<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
        int start;
        cout<<"Enter the starting vertex: ";
        cin>>start;
        cout<<"DFS starting from vertex "<<start<<" :";
        dfs(start,adjList,visited);
    

    return 0;
}