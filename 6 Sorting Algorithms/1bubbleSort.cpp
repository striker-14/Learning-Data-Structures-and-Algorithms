#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {

    bool swapped; // boolean to check if swapping happened or not

    for (int i = 0; i < n-1; i++) { // we iterate i till n-1 (goes till second last) (to prevent accessing arr[j+1] out of bounds in the inner loop)
        
        swapped = false;

        for (int j = 0; j < n-1-i; j++) { // we iterate j till n-i-1 because after each pass(i), element (among remaining) at the end gets sorted
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true; // set it as true as swapping is taking place
            }
        }

        if (!swapped) { // Swapping is not taking place (means array is already sorted), so break out of OUTER loop
            break;
        }
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    bubbleSort(arr, n);

    printArray(arr);

    return 0;
}

// TC: O(n^2)
// SC: O(1) 