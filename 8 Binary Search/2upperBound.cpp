#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int target) {

    int low = 0, high = arr.size()-1;

    int res = arr.size();

    while (low <= high) {
        
        int mid = low + (high-low)/2;

        if (arr[mid] > target) { // # it can only be greater, cannot be equal to the target
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int target = 11;

    cout << upperBound(arr, target);

    return 0;
}

// TC: O(log n)
// SC: O(1)