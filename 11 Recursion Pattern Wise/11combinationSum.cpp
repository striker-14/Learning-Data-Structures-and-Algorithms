#include <bits/stdc++.h>
using namespace std;

// Function to find all unique combination of arr such that their sum is target
void findCombinations(vector<int> &arr, int index, int target, vector<int> &curr, vector<vector<int>> &res) {

    // if a unique combination is found
    if (target == 0) {
        res.push_back(curr);
        return;
    }

    // target is less than 0 or array is exhausted, return to explore other options
    if (target < 0 || index >= arr.size()) {
        return;
    }

    for (int i = index; i < arr.size(); i++) {

        // check if it is repeated or not
        if (i > index && arr[i] == arr[i-1]) {
            continue;
        }

        // take the element into the combination
        curr.push_back(arr[i]);

        findCombinations(arr, i+1, target-arr[i], curr, res);

        // remove element from the combination
        curr.pop_back();
    }
}

// Function to find all combination of the given elements
vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {

    // sort the array to handle duplicates
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    vector<int> curr;

    findCombinations(arr, 0, target, curr, res);

    return res;
}

int main() {
    vector<int> arr = {1, 3, 2, 2, 2};
    int target = 4;

    vector<vector<int>> res = uniqueCombinations(arr, target);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(n*2^n)
// SC: O(n)