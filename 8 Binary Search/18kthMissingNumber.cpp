#include <bits/stdc++.h>
using namespace std;

int kthMissingNumber(vector<int> &arr, int k) {

    int low = 0, high = arr.size()-1;

    int res = arr.size() + k; // in case the missing number lies after the last element

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] > mid + k) { // to detect whether the missing number lies after or before the index mid
            res = mid + k;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};

    int k = 5;

    cout << kthMissingNumber(arr, k);

    return 0;
}

// TC: O(log n)
// SC: O(1)