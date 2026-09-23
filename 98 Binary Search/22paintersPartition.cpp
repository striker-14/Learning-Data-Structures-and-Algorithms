#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int k, int maxTime) {

    int painters = 1;
    int currSum = 0;

    for (int num : arr) {
        if (num > maxTime) {
            return false;
        }

        if (currSum + num > maxTime) {
            painters++;
            currSum = num;
        } else {
            currSum += num;
        }
    }

    return painters <= k;
}

int paintersPartition(vector<int> &arr, int k) {

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int res = high; // in case a single painter paints every board

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (check(arr, k, mid)) {
            res = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};

    int k = 3;

    cout << paintersPartition(arr, k);

    return 0;
}

// TC: O(n*log(sum(arr)-max(arr)))
// SC: O(1)