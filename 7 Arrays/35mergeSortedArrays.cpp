#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, int m, vector<int> &arr2, int n) {

    int idx = m + n - 1;
    int i = m-1;
    int j = n-1;

    while (i >= 0 && j >= 0) {

        if (arr1[i] >= arr2[j]) {
            arr1[idx] = arr1[i];
            idx--;
            i--;
        } else {
            arr1[idx] = arr2[j];
            idx--;
            j--;
        }
    }

    // if some elements of arr2 gets left (# only for arr2)
    while (j >= 0) {
        arr1[idx] = arr2[j];
        idx--;
        j--;
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};

    int m = 3; // length of arr1 = m + n
    int n = 3;

    mergeSortedArrays(arr1, m, arr2, n);

    printArray(arr1);

    return 0;
}

// TC: O(m+n)
// SC: O(1)