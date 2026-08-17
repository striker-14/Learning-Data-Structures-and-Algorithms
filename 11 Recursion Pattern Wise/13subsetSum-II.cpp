#include <bits/stdc++.h>
using namespace std;

// Helper function to find all unique subsets
void findSubsetsRec(vector<int> &arr, int idx, vector<int> &subset, vector<vector<int>> &res) { // idx is the current starting index

    // include current subset
    res.push_back(subset); // Every time this function runs, whatever is currently inside `subset` is a valid combination, so it gets added to our final results list immediately.

    for (int i = idx; i < arr.size(); i++) {

        // skip duplicates at the same recursion level
        if (i > idx && arr[i] == arr[i-1]) {
            continue;
        }

        subset.push_back(arr[i]);
        findSubsetsRec(arr, i+1, subset, res);

        // backtrack
        subset.pop_back();
    }
}

vector<vector<int>> findSubsets(vector<int> &arr) {

    // sort to handle duplicates
    sort(arr.begin(), arr.end());
    vector<vector<int>> res; // to store all the final subsets

    vector<int> subset; // empty subset to keep track of the current combination
    findSubsetsRec(arr, 0, subset, res);

    return res;
}

int main() {
    vector<int> arr = {1, 2, 2};

    vector<vector<int>> result = findSubsets(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}

// TC: O(n*(2^n))
// SC: O(n)