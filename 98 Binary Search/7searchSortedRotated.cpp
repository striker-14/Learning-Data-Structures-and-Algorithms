#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int x) {

    int low = 0, high = arr.size()-1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            return mid;
        }

        // if left half is sorted
        if (arr[mid] >= arr[low]) {

            if (x >= arr[low] && x < arr[mid]) { // # cannot be equal to mid because we have already checked that above
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // if right half is sorted

            if (arr[high] >= x && x > arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1; // key not found
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int x = 3;

    cout << search(arr, x);

    return 0;
}

// TC: O(log n)
// SC: O(1)