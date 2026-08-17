#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> &arr, int k) {

    int n = arr.size();

    // n must be greater
    if (n <= k) {
        cout << "Invalid";
        return -1;
    }

    int maxSum = 0;

    // compute sum of first window of size k
    for (int i = 0; i < k; i++) {
        maxSum += arr[i];
    }

    // computer sums of remaining windows by removing first element of previous window and adding last element of current window
    int windowSum = maxSum;

    for (int i = k; i < n; i++) { // begin from k
        windowSum += arr[i] - arr[i-k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {5, 2, -1, 0, 3};

    int k = 3;

    cout << maxSumSubarray(arr, k);
    
    return 0;
}

// TC: O(n)
// SC: O(1)