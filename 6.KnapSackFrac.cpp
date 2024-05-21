#include <bits/stdc++.h>
using namespace std;
struct Item
{ // Structure to represent an item
    float value;
    float weight;
};

// quicksort
int partition(Item items[], int low, int high)
{
    double pivot = (double)(items[high].value) / items[high].weight;
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        if ((double)(items[j].value) / items[j].weight >= pivot)
        {
            i++;
            Item temp = items[i];
            items[i] = items[j];
            items[j] = temp;
        }
    }
    Item temp = items[i + 1];
    items[i + 1] = items[high];
    items[high] = temp;
    return i + 1;
}

// Quicksort function
void quickSort(Item items[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(items, low, high);
        quickSort(items, low, pi - 1);
        quickSort(items, pi + 1, high);
    }
}
double fractionalKnapsack(Item items[], int n, int capacity)
{
    quickSort(items, 0, n - 1);
    int currentWeight = 0;
    float finalValue = 0.0;
    cout << "Sorted items by value/weight ratio:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": Value = " << items[i].value << ", Weight = " << items[i].weight << endl;
    }
    cout << endl;

    for (int i = 0; i < n && capacity > 0; i++)
    {
        // If the item can be added fully
        if (items[i].weight <= capacity)
        {
            finalValue += items[i].value;
            capacity -= items[i].weight;
            cout << "\nThe previous sum = " << finalValue << "\nThe combination: (" << items[i].value << "," << items[i].weight << ")\n";
        }
        else
        {
            finalValue += items[i].value * ((float)capacity / items[i].weight);
            cout << "\nThe previous sum = " << finalValue << "\nThe combination: (" << items[i].value << "," << items[i].weight << ")\n";
            capacity = 0;
        }
    }

    return finalValue;
}

int main()
{
    Item items[] = {{60, 10}, {200, 20}, {220, 130}, {50, 30}, {100, 10}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    double maxValue = fractionalKnapsack(items, n, capacity);
    cout << "\nMaximum value in knapsack = " << maxValue << endl;
    return 0;
}
