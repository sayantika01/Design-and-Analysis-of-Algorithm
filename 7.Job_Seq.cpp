#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;      // Job Id
    int dead;     // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
};

// Comparison function to sort jobs according to profit
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit sequence of jobs
void printJobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, comparison);

    // To keep track of free time slots
    bool slot[n];

    // To store result (Sequence of jobs)
    char result[n];

    // Initialize all slots to be free
    memset(slot, false, sizeof(slot));
    memset(result, '\0', sizeof(result));

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (note that we start from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (!slot[j]) {
                slot[j] = true;          // Mark this slot as occupied
                result[j] = arr[i].id;   // Add this job to result
                break;
            }
        }
    }

    // Print the result
    cout << "Following is the sequence of jobs that maximizes profit:\n";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter job details (id, deadline, profit) for each job:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> arr[i].id;
        cout << "Deadline: ";
        cin >> arr[i].dead;
        cout << "Profit: ";
        cin >> arr[i].profit;
    }

    printJobScheduling(arr, n);
    return 0;
}
