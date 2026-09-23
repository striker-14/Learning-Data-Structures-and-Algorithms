#include <bits/stdc++.h>
using namespace std;

// function to check whether current speed is enough
bool check(vector<int> &arr, int mid, int k) {

    int totalHours = 0;
    for (int i = 0; i < arr.size(); i++) {
        totalHours += (arr[i] + mid - 1)/mid; // computes the ceiling of arr[i]/mid
    }

    // return true if total hours needed is within limit
    return totalHours <= k;
}

int kokoEating(vector<int> &arr, int k) {

    int low = 1; // because speed cannot be 0 or negative
    int high = *max_element(arr.begin(), arr.end()); // * is a dereference operator (it returns the integer value), otherwise max_element(arr.begin(), arr.end()) returns iterator pointing to the largest element

    int res = high;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (check(arr, mid, k)) {
            res = mid;
            high = mid - 1; // because we have to find the minimum speed
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {5, 10, 3};

    int k = 4;

    cout << kokoEating(arr, k);

    return 0;
}

// TC: O(n log m)
// SC: O(1)