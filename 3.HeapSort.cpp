#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int p){
    int large=p;
    int left=2*p+1;
    int right=2*p+2;
    if(left<n && a[left]>a[large]){
        large=left;
    }
    if(right<n && a[right]>a[large]){
        large=right;
    }
    if(large!=p){
        swap(a[large],a[p]);
        heapify(a,n,large);
    }
}
void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
void printHeap(int a[], int n) {
    int level = 0;
    int elements = 0;
    int next_level_elements = 1;
    
    for (int i = 0; i < n; i++) {
        cout <<a[i] << "   ";
        elements++;
        if (elements == next_level_elements) {
            cout << endl;
            level++;
            elements = 0;
            next_level_elements = pow(2, level);
        }
    }
    cout << endl;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a,n);
    cout<<"The sorted array is: "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<"    ";
    // }
    printHeap(a, n);
    return 0;
}