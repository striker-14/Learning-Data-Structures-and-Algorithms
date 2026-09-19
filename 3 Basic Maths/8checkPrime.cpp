/*
Q8. Check for Prime Number.
A Prime Number is a number greater than 1 that has no positive divisors other than 1 and itself. (# 1 is neither prime nor composite)

We only need to check divisors up to √n because divisors always come in pairs. If a larger divisor exists beyond √n, its smallest paired divisor would have already been checked.

Math        C++

i <= √n     i <= sqrt(n)
sq. b/s   =  
i^2 <= n    i * i <= n
*/

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

// TC: O(√n)
// SC: O(1)