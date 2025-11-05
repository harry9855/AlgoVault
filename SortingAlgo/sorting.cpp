#include <iostream>
#include "sortingAlgo.h"
using namespace std;

int main()
{
    vector<int> vec;
    int n, choice;

    cout << "Enter the size of Array :- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cout << "Enter element " << i + 1 << ": ";
        cin >> num;
        vec.push_back(num);
    }

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    cout << "\nOriginal Array: ";
    for (int x : vec)
        cout << x << " ";

    switch (choice)
    {
    case 1:
        bubbleSort(vec);
        cout << "\n\nUsing Bubble Sort...\n";
        break;
    case 2:
        insertionSort(vec);
        cout << "\n\nUsing Insertion Sort...\n";
        break;
    case 3:
        selectionSort(vec);
        cout << "\n\nUsing Selection Sort...\n";
        break;
    case 4:
        mergeSort(vec, 0, n - 1);
        cout << "\n\nUsing Merge Sort...\n";
        break;
    case 5:
        quickSort(vec, 0, n - 1);
        cout << "\n\nUsing Quick Sort...\n";
        break;
    default:
        cout << "\nInvalid choice!";
        return 0;
    }

    cout << "Sorted Array: ";
    for (int x : vec)
        cout << x << " ";

    return 0;
}