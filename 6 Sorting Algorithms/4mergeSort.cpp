/*
Merge Sort: Sorting algorithm that follows the divide and conquer approach. It works by recursively dividing the input array into smaller subarrays then merging them back together to obtain the sorted array.

1. Divide: Divide the list or array recursively into two halves until it can no more be sorted.

2. Conquer: Each subarray is sorted individually using the merge sort algorithm.

3. Merge: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.

Used for sorting large datasets.

Requires additional memory to store the merged sub-arrays during the sorting process. (Not and in-place sorting algorithm, which means it requires additional memory to store the sorted data)

# Slower than Quick Sort
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {

    int n1 = mid - left + 1; // number of elements (left half)
    int n2 = right - mid; // (right half)

    vector<int> L(n1), R(n2); // declared temporary vectors (n1 is the size of L vector and n2 of R)

    for (int i = 0; i < n1; i++) { // fill the L vector
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int l = 0, r = 0;
    int k = left;

    while (l < n1 && r < n2) {
        if (L[l] <= R[r]) {
            arr[k] = L[l];
            l++;
            k++;
        } else {
            arr[k] = R[r];
            r++;
            k++;
        }
    }

    // For remaining elements becuase either l < n1 or r < n2 condition became false and loop can't continue further
    while (l < n1) {
        arr[k] = L[l];
        l++;
        k++;
    }

    while (r < n2) {
        arr[k] = R[r];
        r++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = left + (right-left)/2;
    
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    int left = 0;
    int right = n-1;

    mergeSort(arr, left, right);

    printArray(arr);

    return 0;
}

// TC: O(log n)
// SC: O(n) // L size + R size = n (total elements copied)