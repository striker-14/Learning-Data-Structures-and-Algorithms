#include <bits/stdc++.h>
using namespace std;

void rotate90Clockwise(vector<vector<int>> &mat) {

    int n = mat.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // j = i + 1 otherwise it swaps with itself
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++) { // reverse each row
        reverse(mat[i].begin(), mat[i].end()); 
    }
}

void printMatrix(vector<vector<int>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9} };
    rotate90Clockwise(mat);

    printMatrix(mat);

    return 0;
}

// TC: O(n^2)
// SC: O(1)