#include <bits/stdc++.h>
using namespace std;

int countFreq(vector<int> &arr, int x) {

    int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); // # we did -arr.begin() to return the index (lower_bound only returns iterator but we need index, subtracting it gives us index)

    int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

    return r - l;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int x = 2;

    cout << countFreq(arr, x);

    return 0;
}

// TC: O(log n) // lower_bound and upper_bound are literally implemented on binary search idea on sorted array
// SC: O(1)