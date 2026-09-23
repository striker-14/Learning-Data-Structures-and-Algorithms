#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<int> res;

    int top = 0, bottom = n-1, left = 0, right = m-1;

    while (top <= bottom && left <= right) { // includes elements at the boundaries as well

        // store top row from left to right
        for (int i = left; i <= right; i++) {
            res.push_back(mat[top][i]); // row remains same only column changes
        }
        top++;

        // store right column from top to bottom
        for (int i = top; i <= bottom; i++) {
            res.push_back(mat[i][right]);
        }
        right--;

        // store bottom row from right to left
        if (top <= bottom) { // we are again giving this condition because top and bottom change inside loop
            for (int i = right; i >= left; i--) {
                res.push_back(mat[bottom][i]); // row remains same only column changes
            }
        }
        bottom--;

        // store left column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res.push_back(mat[i][left]);
            }
        }
        left++;
    }

    return res;
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16} };

    vector<int> result =spiralTraversal(mat);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n*m)
// Sc: O(1)