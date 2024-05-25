#include<bits/stdc++.h>
using namespace std;
void maxmin(int arr[],int n,int i,int j,int &maxi, int &mini){
    if(i==j)
        maxi=mini=arr[i];
    else if(i==j-1){
        if(arr[i]>arr[j]){
            maxi=arr[i];
            mini=arr[j];
        }
        else{
            maxi=arr[j];
            mini=arr[i];
        }
    }
    else{
        int mid=(i+j)/2;
        int maxi1,maxi2;
        int mini1,mini2;
        maxmin(arr,n,i,mid,maxi1,mini1);
        maxmin(arr,n,mid+1,j,maxi2,mini2);
        maxi=max(maxi1,maxi2);
        mini=min(mini1,mini2);
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
    int maxi,mini;
    maxmin(arr,n,0,n-1,maxi,mini);
    cout<<"The maximum value in the array is: "<<maxi<<" and the minimum value is: "<<mini<<endl;
    return 0;
}
/*5
6
78
12
9
2
45
36*/