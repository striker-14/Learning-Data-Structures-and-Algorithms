#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr, int k) {

    int res = 0;

    int start = 0, end = 0;

    // counter to keep track of zeros in current window
    int count = 0;

    while (end < arr.size()) {
        if (arr[end] == 0) {
            count++;
        }

        // shrink the window from left if number of zeros are greater than k
        while (count > k) {
            if (arr[start] == 0) {
                count--;
            }
            start++;
        }

        res = max(res, (end - start + 1));

        // increment end pointer to expand the window
        end++;
    }

    return res;
}

int main() {
    vector<int> arr = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};

    int k = 2;

    cout << maxConsecutiveOnes(arr, k);

    return 0;
}

// TC: O(n)
// SC: O(1)