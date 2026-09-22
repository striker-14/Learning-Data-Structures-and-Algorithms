/*
Sliding Window Technique: Method used to solve problems that involve subarray or substring or window.

- Instead of repeatedly iterating over the same elements, the sliding window maintains a range (or "window") that moves step-by-step through the data, updating results incrementally.

- The main idea is to use the results of previous window to do computations for the next window.

- Commonly used for problems like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.

Example Problem - Maximum Sum of a Subarray with K Elements

Given an array arr[] and an integer k, we need to calculate the maximum sum of a subarray having size exactly k.

Input: arr[] = {5, 2, -1, 0, 3}, k = 3
Output: 6
Explanation: 5, 2, -1

Using the Sliding Window Technique:

1. We compute the sum of the first k elements out of n terms using a linear loop and store the sum in variable windowSum.

2. Then we will traverse linearly over the array till it reaches the end and simultaneously keep track of the maximum sum.

3. To get the current sum of a block of k elements just subtract the first element from the previous block and add the last element of the current block.
*/

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