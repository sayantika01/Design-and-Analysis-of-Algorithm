#include<bits/stdc++.h>
using namespace std;
void max_min(int a[],int i,int j,int maxi,int mini){
    if(i==j){
        maxi=mini=a[i];
    }
    else if(i=j-1){
        if(a[i]>a[j]){
            maxi=a[i];
            mini=a[j];
        }
        else{
            maxi=a[j];
            mini=a[i];
        }
    }
    else{
        int mid=(i+j)/2;
        int maxi2,mini2;
        max_min(a,i,mid,maxi,mini);
        max_min(a,mid+1,j,maxi2,mini2);
        if(maxi2>maxi)
            maxi=maxi2;
        if(mini2<mini)
            mini=mini2;
    }
}
int main(){
    int n,i,maxi,mini;
    cout<<"Enter the numner of elements in the array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: "<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The maximum value and the minimum value in the array are: ";
    max_min(arr,i,n-1,maxi,mini);
    cout<<"Respectively"<<endl;
}