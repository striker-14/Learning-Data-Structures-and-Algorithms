#include <bits/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int> &arr, int x) {

    int low = 0, high = arr.size()-1;

    while (low <= high) {

        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low; // the only difference between BS and this is that in BS we return -1
}

int main() {
    vector<int> arr = {1, 3, 5, 6};
    int x = 4;

    cout << searchInsertPosition(arr, x);

    return 0;
}

// TC: O(log n)
// SC: O(1)