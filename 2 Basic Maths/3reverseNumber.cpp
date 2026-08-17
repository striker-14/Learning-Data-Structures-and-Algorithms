#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {

    int num = 0;

    while (n > 0) {
        
        int lastDigit = n % 10;

        num = num * 10 + lastDigit;

        n = n / 10;
    }

    return num;
}

int main() {
    int n = 10400;
    int ans = reverseNumber(n);
    cout << ans;

    return 0;
}

// TC: O(log n)
// SC: O(1) // number of variables never increases, no matter how big n is (the same n will store all the digits and its size won't increase)