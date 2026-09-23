#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {

    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) { // begin from i = 1
        
        vector<int> &last = res.back(); // stores the last element in the res (.back() points to last element not like .end()). It's a vector so it will store element like {1, 5}
        vector<int> &curr = arr[i];

        if (curr[0] <= last[1]) { // curr[0] means first element in curr vector (2) and last[1] means last element in last vector (5)
            last[1] = max(last[1], curr[1]); // update last[1] to max among the last elements of both vectors and it will directly change the element already pushed in the res because it last is a reference not just a copy of it
        } else {
            res.push_back(curr);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};

    vector<vector<int>> result = mergeOverlappingIntervals(arr);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(n*log n) // we have to sort the elements inside it also the number of times the number of elements are there
// SC: O(n)