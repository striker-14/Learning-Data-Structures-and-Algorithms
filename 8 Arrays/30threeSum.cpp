#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {

    vector<vector<int>> ans; // resultant array

    unordered_map<int, vector<int>> um; // map to store indices

    for (int j = 0; j < arr.size(); j++) {
        for (int k = j+1; k < arr.size(); k++) {

            int val = -1 * (arr[j] + arr[k]); // value of third index should be

            if (um.find(val) != um.end()) {

                // append the i, j, k
                for (auto i : um[val]) {
                    ans.push_back({i, j, k});
                }
            }
        }
        // value if i must be less than j
        um[arr[j]].push_back(j);
    }
    return ans;
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};

    vector<vector<int>> result = threeSum(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}

// TC: O(n^3)
// SC: O(n^2)