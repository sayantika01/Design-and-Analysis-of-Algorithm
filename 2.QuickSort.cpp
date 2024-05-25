#include<bits/stdc++.h>
using namespace std;
int pivot(int a[],int left,int right){
    int pivot=a[left];
    int i=left;
    int j= right;
    while(i<j){
        while(i<=right && a[i]<=pivot){
            i++;
        }
        while(j>=left && a[j]>pivot){
            j--;
        }
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[j],a[left]);
    return j;
}
void quickSort(int a[],int left,int right){
    if(left<right){
        int partition=pivot(a,left,right);
        cout<<"PIVOT: "<<a[partition]<<endl;
        cout<<"Sub Arrays: ";
        for(int i=left;i<=right;i++){
            cout<<a[i]<<"--->";
        }
        cout<<endl;
        cout<<"Array after merge: "<<endl;
        for(int i=left;i<=right;i++){
            cout<<a[i]<<"-->";
        }
        cout<<endl;
        quickSort(a,left,partition-1);
        quickSort(a,partition+1,right);

    }
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
    int left=0;
    int right=n-1;
    quickSort(a,left,right);
    cout<<"The sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<"    ";
    }
    return 0;
}