#include <bits/stdc++.h>
using namespace std;

double power(double b, int e) {

    // base case
    if (e == 0) {
        return 1;
    }

    if (e < 0) {
        return 1 / power(b, -e);
    }
    else {
        return b * power(b, e-1);
    }
}

int main() {
    double b = 3.0;
    int e = 5;

    cout << power(b, e);

    return 0;
}

// TC: O(e)
// SC: O(e)