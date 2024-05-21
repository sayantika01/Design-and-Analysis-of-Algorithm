#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int left, int mid, int right)
{
    int i = left;             // 1`st half 1st index
    int j = mid + 1;          // 2nd half 1st index
    int n = right - left + 1; // number of elements
    int k = 0;                // indexing of a new array
    int *b = new int[n];
    while (i <= mid && j <= right)
    {
        if (a[i] >= a[j])
        {
            b[k] = a[j];
            j++;
        }
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    while (i <= mid)    //Leftover elements in the 1st half
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= right)  //Leftover elements in the 2nd half
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = 0; i < n; i++)
    {
        a[i + left] = b[i];
    }
}
void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
        cout << "Array after merge: " << endl;  //Printing the intermediate steps
        for (int i = left; i <= right; i++)
        {
            cout << a[i] << "-->";
        }
        cout << endl;
    }
}
// void display(int a[], int n)    //Printing the sorted array
// {
//     cout << "The sorted array is: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << "-->";
//     }
//     cout << endl;
// }
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int left = 0;
    int right = n - 1;
    mergeSort(arr, left, right);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "-->";
    }
    //display(arr,n);
    return 0;
}