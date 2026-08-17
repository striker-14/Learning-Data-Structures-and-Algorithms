#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr) {

    int n = arr.size();

    int pivot = -1;

    for (int i = n-2; i >= 0; i--) { // begin from second last element and go till first element
        if (arr[i] < arr[i+1]) { // find the rightmost element that is smaller than its next element
            pivot = i; // index
            break; // break once you have found it (because we need to find the first one)
        }
    }

    // if pivot does not exist, reverse the whole array
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return; // return after that
    }

    for (int i = n-1; i > pivot; i--) { // find the rightmost element that is greater than pivot
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]); // swap the element pivot not index
            break; // break after you have found and swapped (need to find the first one)
        }
    }

    // reverse the element right of pivot
    reverse(arr.begin() + pivot + 1, arr.end());
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};

    nextPermutation(arr);

    printArray(arr);

    return 0;
}

/* 
// Using Inbuilt Function
void nextPermutation(vector<int> &arr) {
    next_permutation(arr.begin(), arr.end());
}
*/

// TC: O(n)
// SC: O(1)