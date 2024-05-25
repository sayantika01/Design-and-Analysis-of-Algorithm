#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};
int partition(Item items[],int left,int right){
    double pivot=double(items[right].value/items[right].weight);
    int i=left-1;
    for(int j=left;j< right-2;j++){
        double pi=double(items[j].value/items[j].weight);
        if(pi>=pivot){
            i++;
            swap(pivot,pi);
        }
    }
    swap(items[i+1],items[right]);
    return i+1;
}
void quick(Item items[],int left,int right){
    if(left<right){
        int piv=partition(items,left,right);
        quick(items,left,piv-1);
        quick(items,piv+1,right);
    }
}
double fracKnap(Item items[],int n,int capacity){
    quick(items,0,n-1);
    int currentWeight=0;
    float finalValue=0.0;
    cout<<"Sorted items by value/weight ratio:" << endl;
    for(int i=0;i<n;i++){
        cout<<"Item "<<i+1<<": value= "<<items[i].value<<" ,Weight= "<<items[i].weight<<endl;
    }
    cout<<endl;
    for(int i=0;i<n && capacity>0;i++){
        if(items[i].weight<=capacity){
            finalValue+=items[i].value;
            capacity-=items[i].weight;
            cout << "\nThe previous sum = " << finalValue << "\nThe combination: (" << items[i].value << "," << items[i].weight << ")\n";
        }
        else{
            finalValue+=items[i].value*((float)capacity/items[i].weight);
            cout << "\nThe previous sum = " << finalValue << "\nThe combination: (" << items[i].value << "," << items[i].weight << ")\n";
            capacity=0;
        }
    }
    return finalValue;
}
int main(){
    Item items[] = {{60, 10}, {200, 20}, {220, 130}, {50, 30}, {100, 10}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    double maxValue = fracKnap(items, n, capacity);
    cout << "\nMaximum value in knapsack = " << maxValue << endl;
    return 0;
}