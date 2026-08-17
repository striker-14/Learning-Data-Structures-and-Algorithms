#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {

    int largest = arr[0]; // declare first element as largest

    for (int i = 1; i < n; i++) { // we iterate from i=1
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    vector<int> arr = {4, 3, 2, 1, 5};
    int n = arr.size();

    int result = largestElement(arr, n);

    cout << result;

    return 0;
}

// TC: O(n)
// SC: O(1)