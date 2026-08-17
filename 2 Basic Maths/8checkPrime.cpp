#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {

    if (n <= 1) { // if n is less than or equal to 1, it can't be a prime number because prime number is greater than 1
        return false;
    }

    for (int i = 2; i * i <= n; i++) { // running a loop from 2 to sqrt(n), i * i is same as sqrt(n), sqrt(n) is a function call and is slow
        if (n % i == 0) {
            return false;
        }
    }

    return true; // if no divisors were found, n is prime
}

int main() {
    int n = 7;
    if (isPrime(n)) {
        cout << n << " is a prime number";
    } else {
    cout << n << " is not a prime number";
    }

    return 0;
}

// TC: O(sqrt(n))
// SC: O(1)