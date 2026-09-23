#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {

    int n = arr.size();

    // if there is only one element
    if (n == 1) {
        return 0;
    }

    // check if first element is peak
    if (arr[0] > arr[1]) {
        return 0;
    }

    // check if last element is peak
    if (arr[n-1] > arr[n-2]) { // n-1 is last element because n is size
        return n-1;
    }

    int low = 1, high = n-2; // # we start search from second element till second last element

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) { // if mid is peak element
            return mid;
        }

        // if next neighbour is greater then peak element will exist in right subarray
        if (arr[mid] < arr[mid+1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0;
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};

    cout << peakElement(arr);

    return 0;
}

// TC: O(log n)
// SC: O(1)