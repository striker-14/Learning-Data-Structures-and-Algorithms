#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target) {

    vector<vector<int>> ans; // to store the quadruplets

    int n = arr.size();

    // sort the array
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

        // skip duplicates for i
        if (i > 0 && arr[i] == arr[i-1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {

            // skip duplicates for j
            if (j > 0 && arr[j] == arr[j-1]) {
                continue;
            }

            int k = j + 1, l = n - 1;

            while (k < l) {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];

                if (sum == target) {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    // skip duplicates for k and l
                    while (k < l && arr[k] == arr[k-1]) {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l-1]) {
                        l--;
                    }
                }
                else if (sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 2, 3, 4, 5, 7, 8};
    int target = 23;

    vector<vector<int>> result = fourSum(arr, target);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(n^3)
// SC: O(k)