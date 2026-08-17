#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[high];

    int i = low-1; // -1 in first iteration
    int j = 0;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; // increment i first
            swap(arr[i], arr[j]); // no need to increment j as it is already happening inside the for loop
        }
    }

    // Place the pivot at its correct position
    swap(arr[i+1], arr[high]); // cannot write pivot here (you will have to write arr[high]) becuase pivot is just a copy not part of the actual array (for the swap to take place)
    return i + 1; // return the index of pivot
}

void quickSort(vector<int> &arr, int low, int high) {

    if (low < high) { // sort only if there are atleast 2 elements

        int pi = partition(arr, low, high); // get the partition index (pivot position)

        quickSort(arr, low, pi-1); // doesn't include pivot
        quickSort(arr, pi+1, high); // doesn't include pivot
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    int low = 0;
    int high = n-1;

    quickSort(arr, low, high);

    printArray(arr);

    return 0;
}

// TC: O(n^2) // because each recursive call does O(n) work (traversing), and this happens for n recursive levels
// SC: O(n) // because of recursion stack