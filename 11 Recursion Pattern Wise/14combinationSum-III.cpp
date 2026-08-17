#include <bits/stdc++.h>
using namespace std;

// Function to find all valid combinations
void findCombinations(int n, int k, vector<int> &subVector, vector<vector<int>> &res, int start) {

    // base case: if exact sum and exact count achieved
    if (n == 0 && k == 0) {
        res.push_back(subVector);
        return;
    }

    // if sum or count becomes negative, backtrack
    if (n < 0 || k < 0) {
        return;
    }

    // try numbers from start (1) to 9
    for (int i = start; i <= 9; i++) {

        // choose the number
        subVector.push_back(i);
        findCombinations(n-i, k-1, subVector, res, i+1);

        // backtrack
        subVector.pop_back();
    }
}

// Function to generate and print all combinations
vector<vector<int>> combinationSumIII(int n, int k) {
    
    // check if combination is impossible
    if (n < k || n > 9 * k) {
        return { };
    }

    vector<int> subVector;

    vector<vector<int>> res;

    findCombinations(n, k, subVector, res, 1);

    return res;
}

int main() {
    int n = 9, k = 3;
    
    vector<vector<int>> result = combinationSumIII(n, k);

    for (auto &comb : result) {
        for (int x : comb) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(k x C(9, k))
// SC: O(k)