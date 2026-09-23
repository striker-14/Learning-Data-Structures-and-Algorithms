#include <bits/stdc++.h>
using namespace std;

int numAppearingOnce(vector<int> &arr) {

    int xorr = 0; // xor is a reserved keyword (xor = ^)

    for (int i = 0; i < arr.size(); i++) {
        xorr = xorr ^ arr[i];
    }

    return xorr;
}

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};

    cout << numAppearingOnce(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)