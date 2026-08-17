#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {

    vector<int> ansRow; // to store current row

    int res = 1; // element

    ansRow.push_back(1); // first element of row is always 1

    for (int col = 1; col < row; col++) {

        res = res * (row - col);
        res = res / col;

        ansRow.push_back(res);
    }

    return ansRow;
}

vector<vector<int>> pascalsTriangle(int n) {
    
    vector<vector<int>> finalResult;

    for (int i = 1; i <= n; i++) { // we intialize i = 1

        finalResult.push_back(generateRow(i));
    }

    return finalResult;
}

int  main() {
    int n = 5;

    vector<vector<int>> result = pascalsTriangle(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) { // result[i].size() because number of columns in each row is different
            cout << result [i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(n^2)
// SC: O(n^2)