#include <bits/stdc++.h>
using namespace std;

void subsetSumI(vector<int> &arr, int l, int r, int sum = 0) {

    if (l > r) {
        cout << sum << " ";
        return;
    }

    // subset including arr[l]
    subsetSumI(arr, l+1, r, sum + arr[l]);

    // subset excluding arr[i]
    subsetSumI(arr, l+1, r, sum);
}

int main() {
    vector<int> arr = {5, 4, 3};
    int n = arr.size();

    subsetSumI(arr, 0, n-1);

    return 0;
}

// TC: O(2^n)
// SC: O(n)