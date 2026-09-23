#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &arr, int k) {

    int low = 1; // low = 1
    int high = *max_element(arr.begin(), arr.end()); // max element not max index
    int res = 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        int sum = 0;
        for (int ele : arr) {
            sum += (ele + mid - 1)/mid; // add ceil of each value to sum
        }

        if (sum <= k) {
            res = mid;
            high = mid - 1; // because we have to find the minimum value
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 2, 5, 9};

    int k = 6;

    cout << smallestDivisor(arr, k);
    
    return 0;
}

// TC: O(n*log(max(arr))) // search space size is max(arr) and n because they loop over the ENTIRE array in each iteration to compute sum
// SC: O(1)