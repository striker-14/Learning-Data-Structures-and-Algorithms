#include <bits/stdc++.h>
using namespace std;

void setMatrixRowsandCols(vector<vector<int>> &mat) {

    int n = mat.size();
    int m = mat[0].size();

    int c0 = 1; // special variable for first column (separately tracks whether the first column should be zeroed)

    // loop to mark rows and columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) { // if any element is zero

                // mark its row as zero (mark first column of row as zero)
                mat[i][0] = 0;

                if (j == 0) {
                    c0 = 0; // if j is zero then mark c0 = 0 (why separately like this because we mark first column of row zero, so to avoid intersection we do this (because first column is already marked zero by row)
                } else {
                    mat[0][j] = 0; // otherwise mark that particular column in first row
                }
            }
        }
    }

    // loop to place zeros
    for (int i = 1; i < n; i++) { // from i = 1 element because first element is already marked zero
        for (int j = 1; j < m; j++) {

            if (mat[i][0] == 0 || mat[0][j] == 0) { // only reading
                mat[i][j] = 0; // if they are marked zero set cell to zero
            }
        }
    }

    // handle first row
    if (mat[0][0] == 0) { // if, then entire first row must be zero
        for (int j = 0; j < m; j++) {
            mat[0][j] = 0;
        }
    }

    // handle first column
    if (c0 == 0) { // if, then entire first column must be zero
        for (int i = 0; i < n; i++) {
            mat[i][0] = 0;
        }
    }
}

void printMatrix(vector<vector<int>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl; // shift to next row after one loop
    }
}

int main() {
    vector<vector<int>> mat = { {0, 1, 2, 0},
                                {3, 4, 0, 2},
                                {1, 3, 1, 5} };
    
    setMatrixRowsandCols(mat);

    printMatrix(mat);

    return 0;
}

// TC: O(n*m)
// SC: O(1)