#pragma once

#include <iostream>
#include <vector>
using namespace std;

// BUBBLE SORT ---------> 1
void bubbleSort(vector<int> &vec)
{
    int n = vec.size();
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}

// INSERTION SORT --------> 2
void insertionSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        int key = vec[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (vec[j] > key)
            {
                vec[j + 1] = vec[j];
            }
            else
            {
                break;
            }
        }
        vec[j + 1] = key;
    }
}

// SELECTION SORT --------> 3
void selectionSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (vec[min] > vec[j])
            {
                min = j;
            }
        }
        int temp = vec[min];
        vec[min] = vec[i];
        vec[i] = temp;
    }
}

// MERGE SORT --------> 4
void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(vec[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        vec[i] = temp[i - low];
    }
}
// PART OF MERGE SORT
void mergeSort(vector<int> &vec, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

// QUICK SORT -----> 5
int partition(vector<int> &vec, int low, int high)
{
    int pivot = vec[low];
    int i = low + 1;
    int j = high;

    while (true)
    {

        while (i <= j && vec[i] <= pivot)
            i++;

        while (i <= j && vec[j] > pivot)
            j--;

        if (i > j)
            break;

        swap(vec[i], vec[j]);
    }

    swap(vec[low], vec[j]);
    return j;
}

// QuickSort recursive function
void quickSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(vec, low, high);
        quickSort(vec, low, pivotIndex - 1);
        quickSort(vec, pivotIndex + 1, high);
    }
}