#include<bits/stdc++.h>
using namespace std;
void matdisplay(int n, int** S,int i,int j){
    if(i==j){
        cout<<"A";
    }
    else{
        cout<<"(";
        matdisplay(n,S,i,S[i][j]);
        matdisplay(n,S,S[i][j]+1,j);
        cout<<")";
    }
}
void matmul(int p[],int n){
    int **M=new int*[n];
    int **S=new int*[n];
    int i=0,j=0;
    for(i=0;i<n;i++){
        M[i]=new int[n];
        S[i]=new int[n];
    }
    for(i=0;i<n;i++){
        M[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(i=0;i<n-l+1;i++){
            j=i+l-1;
            M[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int c=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
                if(c<M[i][j]){
                    M[i][j]=c;
                    S[i][j]=k;
                }
            }
        }
    }
    cout<<"Table for M: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i){
                cout<<" \t";
            }
            else{
                cout<<M[i][j]<<" \t";
            }
        }
        cout<<endl;
    }
    cout<<"Table for S: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i){
                cout<<" \t";
            }
            else{
                cout<<S[i][j]<<" \t";
            }
        }
        cout<<endl;
    }
    matdisplay(n,S,0,n-1);
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int p[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    matmul(p,n);
    return 0;
}