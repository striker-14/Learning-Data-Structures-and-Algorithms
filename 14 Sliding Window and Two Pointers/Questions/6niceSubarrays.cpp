#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int> &arr, int k) {

    int n = arr.size();

    int odd = 0;
    int res = 0;

    // to mark the start of subarray
    int start = 0;

    for (int i = 0; i < n; i++) {

        // if current element is odd
        if (arr[i] % 2) {
            odd++;
        }

        // if count of odd elements is greater than x then remove elements from the start
        while (odd > k) {
            if (arr[start] % 2) {
                odd--;
            }
            start++;
        }

        // add the number of subarrays with at most k odd elements ending at the current index
        res += i - start + 1;
    }

    return res;
}

int niceSubarrays(vector<int> &arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k-1);
}

int main() {
    vector<int> arr = {2, 2, 5, 6, 9, 2, 11};

    int k = 2;

    cout << niceSubarrays(arr, k);

    return 0;
}

// TC: O(n)
// SC: O(1)