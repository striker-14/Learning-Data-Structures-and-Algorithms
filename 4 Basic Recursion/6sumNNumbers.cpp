/*
Q6. Sum of first n numbers.
*/

#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    if (n > 0) {
        return n + sum(n-1);
    } else {
        return 0; // We return 0 here, not just return
    }
}

int main() {
    int n = 10;
    cout << sum(n);

    return 0;
}