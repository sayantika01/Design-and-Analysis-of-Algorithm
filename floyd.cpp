#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 99999
void print(int dist[MAX][MAX],int V){
    cout<<"The resultant Matrix is as follows: "<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<"\t";
            }
            else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}
void floyd(int graph[MAX][MAX], int V){
    int dist[MAX][MAX];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]!= INF && dist[k][j]!= INF && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    print(dist,V);
}
int main(){
    int V;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    int graph[MAX][MAX];
    cout<<"Enter the elements in the matrix: "<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
            if(i==j){
                graph[i][j]=0;
            }
        }
    }
    floyd(graph,V);
}

/*0 3 99999 7
8 2 0 99999
5 99999 4 0
2 99999 99999 0*/