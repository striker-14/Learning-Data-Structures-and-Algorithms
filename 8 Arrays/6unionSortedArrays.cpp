#include <bits/stdc++.h>
using namespace std;

vector<int> unionSortedArrays(int arr1[], int arr2[], int n, int m) {

    vector<int> result; // vector to store union of two sorted arrays

    int i = 0;
    int j = 0; // pointers
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            if (result.size() == 0 || result.back() != arr1[i]) { // either there are no elements present already or last element inserted in not the same as current element (# the parent arrays are also sorted)
                result.push_back(arr1[i]);
            }
            i++; // notice it's position, if duplicate element, it moves to next element (if the if condition is satisfied)
        } else {
            if (result.size() == 0 || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        }
    }

    // For remaining elements if either i < n or j < m is no longer true
    while (i < n) {
        if (result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++; // same here also, if the remaining elements are duplicated, just iterate them and over
    }

    while (j < m) {
        if (result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result; // return the union vector
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    vector<int> result = unionSortedArrays(arr1, arr2, n, m);

    printArray(result);

    return 0;
}

// TC: O(m+n)
// SC: O(m+n)