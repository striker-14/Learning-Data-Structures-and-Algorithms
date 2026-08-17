#include <bits/stdc++.h>
using namespace std;

int maxProdSubarray(vector<int> &arr) {

    int currMax = arr[0];

    int currMin = arr[0];

    int maxProd = arr[0];

    for (int i = 1; i < arr.size(); i++) { // i = 1

        // temporary variable to store currMax (# because if we won't do that currMin will use the updated value of currMax)
        int temp = max({arr[i], arr[i] * currMax, arr[i] * currMin}); // # we have used {} here because the number of values are 3 (or 3+)

        currMin = min({arr[i], arr[i] * currMax, arr[i] * currMin});

        currMax = temp;

        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> arr = {-2, 6, -3, -10, 0, 2};

    cout << maxProdSubarray(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)