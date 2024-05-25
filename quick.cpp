#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int left,int right){
    int pivot=arr[left];
    int i=left;
    int j=right;
    while(i<j){
        while(i<=right && i<=pivot){
            i++;
        }
        while(j>=left && j>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[left]);
    return j;
}
void quick(int arr[], int left,int right){
    if(left<right){
        int pivot=partition(arr,left,right);
        cout<<"PIVOT: "<< arr[pivot]<<endl;
        cout<<"SUB Arry: "<<endl;
        for(int i=left;i<right;i++){
            cout<<arr[i]<<" -->";
        }
        cout<<endl;

        cout<<"The array after sort: "<<endl;
        for(int i=left;i<=right;i++){
            cout<<arr[i]<<" -->";
        }
        cout<<endl;
        quick(arr,left,pivot-1);
        quick(arr,pivot+1,right);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick(arr,0,n-1);

    cout<<"The sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" < ";
    }
    cout<<endl;
    return 0;
}