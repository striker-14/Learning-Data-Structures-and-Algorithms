#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumSubarray(vector<int> &arr) {

    int resStart = 0, resEnd = 0;

    int currStart = 0;

    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {

        if (maxEnding + arr[i] < arr[i]) {

            maxEnding = arr[i];
            currStart = i;
        }
        else {
            maxEnding += arr[i];
        }


        if (maxEnding > res) {
            res = maxEnding;

            resStart = currStart;
            resEnd = i;
        }
    }

    vector<int> ans;
    for (int i = resStart; i <= resEnd; i++) { // includes resEnd
        ans.push_back(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    vector<int> result = maxSumSubarray(arr);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(1)