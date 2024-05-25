#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int n = right - left + 1;
    int *b = new int[n];
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] >= arr[j])
        {
            b[k] = arr[j];
            j++;
        }
        else
        {
            b[k] = arr[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (i = 0; i < n; i++)
    {
        arr[i + left] = b[i];
    }
}
void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        cout << "Array after merge: " << endl;
        for (int i = left; i <= right; i++)
        {
            cout << arr[i] << " --> ";
        }
        cout << endl;
    }
}
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
    int left = 0;
    int right = n - 1;
    mergesort(arr, left, right);

    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " < ";
    }
    return 0;
}