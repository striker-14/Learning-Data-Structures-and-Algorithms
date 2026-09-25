/*
Q4. Remove Duplicates in-place from Sorted Array.
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {

    int i = 0;
    for (int j = 1; j < n; j++) { // we begin j from 1
        if (arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            i++; // increment i on successfull addition of new element into the main array (the i will be at i+1 position after this increment)
        }
    }
    return i + 1; // number of unique elements (# the next position after the last unique element)
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3}; // sorted array
    int n = arr.size();

    int k = removeDuplicates(arr, n);

    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    } 

    return 0;
}

// TC: O(n)
// SC: O(1)