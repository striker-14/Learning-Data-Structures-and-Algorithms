#include <bits/stdc++.h>
using namespace std;

int stockbuysell(vector<int> &arr) {

    int minPrice = INT_MAX; // largest possible value an int can store

    int maxProfit = 0;

    for (int num : arr) {
        if (num < minPrice) {
            minPrice = num;
        }
        else {
            maxProfit = max(maxProfit, num - minPrice);
        }
    }

    return maxProfit;
}

int main() {
    vector<int> arr = {7, 1, 5, 3, 6, 4};

    cout << stockbuysell(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)