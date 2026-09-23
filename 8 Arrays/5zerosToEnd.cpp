#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &arr, int n) {

    int j = -1; // assign j's position (index)
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) { // identify first zero element's position (that's all you need, need to do it only once)
            j = i; // assign it to j
            break; // break the loop once you have found it (because we only need the position of first zero element)
        }
    }

    // in case there are only non-zero elements
    if (j == -1) {
        return;
    }

    for (int i = j+1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++; // so that it comes back to zero element's position
        }
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();

    moveZeros(arr, n);

    printArray(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)