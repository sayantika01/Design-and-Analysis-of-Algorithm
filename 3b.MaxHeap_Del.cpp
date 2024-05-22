#include <bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void deleting(int a[], int &n)
{
    int leaf = a[n - 1];
    a[0] = leaf;
    n = n - 1;
    heapify(a, n, 0);
}
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
    deleting(arr,n);
    display(arr,n);
    return 0;
}

