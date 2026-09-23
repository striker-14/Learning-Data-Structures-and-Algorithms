#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int k) {

    int n = arr.size();

    int maxLen = 0;

    int left = 0;
    int right = 0;

    int sum = arr[0]; // because left and right are already at zero and they should contatin 0 index element

    while (right < n) {

        if (left <= right && sum > k) { // if sum becomes greater than k
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right-left+1);
        }

        right++; // notice here than right++ if before because sum already contains the element on the first index
        if (right < n) {
            sum += arr[right];
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {2, 3, 5, 1, 9};

    int k = 10;

    cout << longestSubarray(arr, k); // we have to print the length of longest subarray

    return 0;
}

// TC: O(n)
// SC: O(1)