#include <bits/stdc++.h>
using namespace std;

int longestSubarray0Sum(vector<int> &arr) {

    int n = arr.size();

    unordered_map<int, int> firstSeen;

    int prefixSum = 0;
    int maxLen = 0;

    firstSeen[0] = -1; // insert prefixSum 0 at index -1 (to handle sum from start)

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // if prefixSum is seen before
        if (firstSeen.find(prefixSum) != firstSeen.end()) {
            int prevIndex = firstSeen[prefixSum]; // store index where it had occurred before
            int length = i - prevIndex;

            maxLen = max(maxLen, length);
        }
        else { // if prefixSum is not seen before
            firstSeen[prefixSum] = i; // store it in the map with the current index
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    cout << longestSubarray0Sum(arr);

    return 0;
}

// TC: O(n) // average tc of .find() is O(1)
// SC: O(n)