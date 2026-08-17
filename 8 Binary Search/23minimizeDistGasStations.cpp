#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int k, double d) {

    int used = 0;

    for (int i = 0; i < (int)arr.size()-1; i++) { // because we are comparing pairs
        used += (int)((arr[i+1]-arr[i])/d);
    }

    return used <= k;
}

double minimizeMaximumDistance(vector<int> &arr, int k) {

    double low = 0, high = 1e8;

    while (high - low > 1e-6) {
        double mid = low + (high-low)/2;

        if (check(arr, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return low;
}

int main() {
    vector<int> arr = {3, 6, 12, 19, 33};

    int k = 3;

    cout << minimizeMaximumDistance(arr, k);

    return 0;
}

// TC: O(n*log m)
// SC: O(1)