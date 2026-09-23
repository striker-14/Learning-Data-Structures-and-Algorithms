#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr, int n) {
    for (int i = 0; i < n-1; i++) { // we iterate till n-1 (because of i+1)
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true; // return true if it is sorted
}

int main() {
    vector<int> arr = {5, 3, 1, 2, 4};
    int n = arr.size();

    if (isSorted(arr, n)) {
        cout << "Sorted";
    } else {
        cout << "Not Sorted";
    }

    return 0;
}