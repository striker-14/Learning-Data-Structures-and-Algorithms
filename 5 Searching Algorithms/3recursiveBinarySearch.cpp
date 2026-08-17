#include <bits/stdc++.h>
using namespace std;

int recursiveBinarySearch(vector<int> &arr, int x, int low, int high) {

    if (low <= high) { // Don't use while loop in recursive BS because Recursion works by function calling itself, not by looping

        int mid = low + (high - low)/2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            return recursiveBinarySearch(arr, x, mid + 1, high); // Set low as mid + 1
        } else {
            return recursiveBinarySearch(arr, x, low, mid - 1); // Set high as mid - 1
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int low = 0;
    int high = arr.size() - 1;

    int result = recursiveBinarySearch(arr, x, low, high);

    if (result == -1) {
        cout << "Not Present";
    } else {
        cout << "Present at index: " << result;
    }

    return 0;
}

// TC: O(log n)
// SC: O(log n) // Each recursive call uses some memory on the call stack