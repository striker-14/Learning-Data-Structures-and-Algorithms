#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int> &arr, int k) {

    unordered_map<int, int> freq;

    int res = 0;

    int left = 0;

    for (int right = 0; right < arr.size(); right++) {

        freq[arr[right]]++;

        // if this is a new element (the one whose frequency we increased above) in the window, decrement the count of k by 1
        if (freq[arr[right]] == 1) {
            k--;
        }

        // if k becomes less than 0, then decrement the frequency from left
        while (k < 0) {
            freq[arr[left]]--;

            // if the frequency of left element becomes 0
            if (freq[arr[left]] == 0) {
                k++;
            }
            left++;
        }

        // add all possible subarrays to the result
        res += (right - left + 1);
    }

    return res;
}

int exactlyKDistinct(vector<int> &arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k-1);
}

int main() {
    vector<int> arr = {1, 2, 2, 3};

    int k = 2;

    cout << exactlyKDistinct(arr, k);

    return 0;
}

// TC: O(n)
// SC: O(n)