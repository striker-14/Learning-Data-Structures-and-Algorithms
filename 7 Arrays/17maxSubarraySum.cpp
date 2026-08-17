#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {

    int res = arr[0]; // maximum sum found so far

    int maxEnding = arr[0]; // maximum sum of subarray at current position

    for (int i = 1; i < arr.size(); i++) { // i = 1

        maxEnding = max(maxEnding + arr[i], arr[i]);

        res = max(res, maxEnding);
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    cout << maxSubarraySum(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)