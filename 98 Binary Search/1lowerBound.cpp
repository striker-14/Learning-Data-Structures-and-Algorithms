#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target) {

    int low = 0, high = arr.size()-1;
    
    int res = arr.size();

    while (low <= high) {
        
        int mid = low + (high-low)/2;

        if (arr[mid] >= target) { // # can be equal to the target as well
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1; // didn't update res here because it could be that target is greater than all elements
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25}; // sorted array
    int target = 9;

    cout << lowerBound(arr, target); // returns index

    return 0;
}

// TC: O(log n)
// SC: O(1)