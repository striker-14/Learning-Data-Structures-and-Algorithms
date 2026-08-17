#include <bits/stdc++.h>
using namespace std;

int findRotation(vector<int> &arr) { // we basically have to find the index of minimum element that will give us the rotation times

    int low = 0, high = arr.size()-1;

    while (low <= high) {

        // is subarray is already sorted
        if (arr[low] <= arr[high]) {
            return low;
        }

        int mid = low + (high-low)/2;

        if (arr[mid] > arr[high]) { // minimum is in the right half
            low = mid + 1;
        } else {
            high = mid; // can also be mid
        }
    }

    return low;
}

int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};

    cout << findRotation(arr);

    return 0;
}

// TC: O(log n)
// SC: O(1)