#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {

    int low = 1, high = n; // # we are beginning from 1 and going till n
    int res = 1; // # the floor of sqrt(n) is atleast 1

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (mid * mid <= n) {
            res = mid;
            low = mid + 1; // if mid * mid is less then move to right subarray
        } else {
            high = mid - 1;
        }
    }

    return res;
}

int main() {

    int n = 11;

    cout << floorSqrt(n);

    return 0;
}

// TC: O(log n)
// SC: O(1)