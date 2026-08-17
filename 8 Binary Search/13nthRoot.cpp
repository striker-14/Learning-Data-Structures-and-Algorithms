#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m) {

    int low = 1, high = m; // low = 1 and high = m (27)

    while (low <= high) {
        int mid = low + (high-low)/2;

        int res = 1;
        for (int i = 0; i < n; i++) { // loop will only run till i < n (3) = 2
            res *= mid;
            if (res > m) {
                break;
            }
        }

        // if loop ends because of i < n condition
        if (res == m) {
            return mid;
        }

        if (res > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // if not found
}

int main() {

    int n = 3, m = 27;

    cout << nthRoot(n, m);

    return 0;
}

// TC: O(n*log n)
// SC: O(1)