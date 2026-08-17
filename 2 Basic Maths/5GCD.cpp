#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {

    while (a > 0 && b > 0) { // When one of them becomes zero, stop the loop

        if (a > b) {
            a = a % b; // Remainder of a (larger value) divided by b
        } else {
            b = b % a;
        }
    }

    if (a == 0) { // It won't come under loop because loop will print a if a is not zero
        return b; // return b as it will be the gcd
    } else {
        return a;
    }
}

int main() {
    int a = 20, b = 15;
    cout << "GCD of " << a << " and " << b << " is " << GCD(a, b);

    return 0;
}