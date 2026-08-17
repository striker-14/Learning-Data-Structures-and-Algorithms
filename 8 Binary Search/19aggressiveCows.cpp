#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &stalls, int k, int dist) {

    int prev = stalls[0]; // we place first cow at first stall
    int count = 1; // count of cows placed

    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] - prev >= dist) { // if current stall is at least dist away from previous place
            prev = stalls[i];
            count++;
        }
    }

    return (count >= k); // return true if we are able to place all k cows
}

int aggressiveCows(vector<int> &stalls, int k) {

    // sorting to ensure all stalls in sequence
    sort(stalls.begin(), stalls.end());

    int res = 0;

    // search space for binary search
    int low = 1; // we have already set first place
    int high = stalls.back() - stalls[0];

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (check(stalls, k, mid)) { // if mid distance is possible update the result and search for larger distance
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return res;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};

    int k = 3;

    cout << aggressiveCows(stalls, k);

    return 0;
}

// TC: (n log(max distance))
// SC: O(1)