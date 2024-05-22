#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int& n, int index){
    int parent = (index - 1) / 2;
    if(parent>=0){
        if(a[index]>a[parent]){
            swap(a[index],a[parent]);
            heapify(a,n,parent);
        }
    }
}
void insert(int a[],int& n, int key){
    n=n+1;
    a[n-1]=key;
    heapify(a,n,n-1);
}
// void deleting(int a[],int& n){
//     int leaf=a[n-1];
//     a[0]=leaf;
//     n=n-1;
//     heapify(a,n,0);
// }
void display(int a[], int n){
    cout<<"The heapified array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, key;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    display(arr,n);
    cout<<"Enter the key element: ";
    cin>>key;
    insert(arr,n,key);
    display(arr,n);
    // deleting(arr,n);
    // display(arr,n);
    return 0;
}