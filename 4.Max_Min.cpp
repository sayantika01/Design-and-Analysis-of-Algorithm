#include<bits/stdc++.h>
using namespace std;
void max_min(int a[],int i,int j,int &maxi,int &mini){
    if(i==j){
        maxi=mini=a[i];
    }
    else if(i==j-1){
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
        int maxi2,mini2,maxi1,mini1;
        max_min(a,i,mid,maxi1,mini1);
        max_min(a,mid+1,j,maxi2,mini2);
        maxi=max(maxi1,maxi2);
        mini=min(mini1,mini2);
    }
}
int main(){
    int n;
    cout<<"Enter the numner of elements in the array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi,mini;
    max_min(arr,0,n-1,maxi,mini);
    cout<<"The maximum value and the minimum value in the array are: "<<maxi<<" and "<<mini<<"Respectively"<<endl;
}