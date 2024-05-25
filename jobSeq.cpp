#include <bits/stdc++.h>
using namespace std;
struct Job
{
    char Id;
    int dead;
    int profit;
};
bool comparision(Job a, Job b)
{
    return (a.profit > b.profit);
} 
void jobSeq(Job arr[], int n)
{
    sort(arr, arr + n, comparision);

    bool slot[n];
    char result[n];

    memset(slot, false, sizeof(slot));
    memset(result, '\0', sizeof(result));

    /*for (int i = 0; i < n; i++) {
        slot[i] = false;
        result[i] = '\0';
    }*/  // For the above memset function without using STL;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead); j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[i] = true;
                result[i] = arr[i].Id;
                break;
            }
        }
    }
    cout << "Following is the sequence of jobs that can maximix=ze the profit: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of jobs: " << endl;
    cin >> n;
    Job arr[n];
    cout << "Enter the job details( ID Deadline Profit): " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Job " << i + 1 << ": " << endl;
        cout << "ID: ";
        cin >> arr[i].Id;
        cout << "Deadline: ";
        cin >> arr[i].dead;
        cout << "Profit: ";
        cin >> arr[i].profit;
    }
    jobSeq(arr, n);
    return 0;
}