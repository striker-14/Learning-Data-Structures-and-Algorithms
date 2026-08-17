#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int k, int mid) {

    int count = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mid) {
            return false;
        }

        sum += arr[i];

        if (sum > mid) {
            count++;
            sum = arr[i];
        }
    }

    count++;

    if (count <= k) {
        return true;
    }

    return false;
}

int splitArray(vector<int> &arr, int k) {

    int low = *max_element(arr.begin(), arr.end()); // max array element
    int high = 0; // maximum sum

    for (int i = 0; i < arr.size(); i++) {
        high += arr[i];
    }

    int res = 0;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (check(arr, k, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    int k = 3;

    cout << splitArray(arr, k);
    
    return 0;
}

// TC: O(n*log(sum))
// SC: O(1)