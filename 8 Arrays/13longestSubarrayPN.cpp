#include <bits/stdc++.h>
using namespace std;

int longestSubarrayPN(vector<int> &arr, int k) {

    unordered_map<int, int> um;

    int res = 0;
    int prefSum = 0;

    for (int i = 0; i < arr.size(); i++) { 
        prefSum += arr[i];
        
        if (prefSum == k) { // loop is continuing it hasn't ended
            res = i + 1;
        }
        
        else if (um.find(prefSum - k) != um.end()) {
            res = max(res, i - um[prefSum - k]);
        }
        
        if (um.find(prefSum) == um.end()) { // prefSum does not exist in the map yet
            um[prefSum] = i; // the prefix sum first occured at index i
        }
    }

    return res;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout << longestSubarrayPN(arr, k);

    return 0;
}

// TC: 
// SC: O(n)