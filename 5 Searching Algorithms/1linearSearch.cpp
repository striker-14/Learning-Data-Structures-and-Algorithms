#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            return i;
        } // Didn't use else here otherwise it would have returned -1 for every value of arr[i] that is not equal to x
    }
    return -1; // If the loop fails then return -1
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10; // Key

    int result = linearSearch(arr, x);

    if (result == -1) {
        cout << "Not Present";
    } else {
        cout << "Present at index: " << result;
    }

    return 0;
}

// TC: O(n)
// SC: O(1)