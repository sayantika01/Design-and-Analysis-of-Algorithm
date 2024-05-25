#include<bits/stdc++.h>
using namespace std;
void print(int x[],int n,int& count){
    cout<<"Solution "<<count++<<": "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i]==j)
                cout<<" Q";
            else
                cout<<" -";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool place(int x[],int q,int i){
    for(int j=1;j<q;j++){
        if(x[j]==i || abs(x[j]-i)==(q-j)){
            return false;
        }
    }
    return true;
}
void queen(int x[],int q,int n,int& count){
    if(q==n+1){
        print(x,n,count);
    }
    else{
        for(int i=1;i<=n;i++){
            if(place(x,q,i)){
                x[q]=i;
                queen(x,q+1,n,count);
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of the board: ";
    cin>>n;
    int q;
    cout<<"Enter the number of queens: ";
    cin>>q;
    int x[100];
    int count=1;
    queen(x,1,q,count);
}
