#include <bits/stdc++.h>
using namespace std;

void leftRotateOne(vector<int> &arr, int n) {

    int temp = arr[0]; // create a temp variable to store the value of first element
    for (int i = 0; i < n-1; i++) { // iterate till n-1 (one element less than the size)
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    leftRotateOne(arr, n);

    printArray(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)