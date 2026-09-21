/*
Q7. Factorial of n.
*/

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {

    if (n == 0) { // we do here for 0 only and not for 1 because any other element would simply return itself, it's only 0 that returns 1
        return 1;
    }

    return n * factorial(n-1);
}

int main() {
    int n = 7;
    cout << factorial(n);

    return 0;
}