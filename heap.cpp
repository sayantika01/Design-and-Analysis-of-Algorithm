#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n, int p){
    int large=p;
    int left=2*p+1;
    int right= 2*p+2;
    if(left<n && arr[left]>arr[large]){
        large=left;
    }
    if(right<n && arr[right]>arr[large]){
        large=right;
    }
    if(large!=p){
        swap(arr[large],arr[p]);
        heapify(arr,n,large);
    }
}
void heap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void print(int arr[],int n){
    //cout<<"The sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of elements in the heap: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heap(arr,n);
    cout<<"The sorted array is: "<<endl;
    print(arr,n);
    return 0;
}