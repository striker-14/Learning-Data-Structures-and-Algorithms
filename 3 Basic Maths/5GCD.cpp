/*
Q5. GCD (Greatest Common Divisor) or HCF (Highest Common Factor).

HCF: The largest positive integer that divides two or more numbers without leaving a remainder.

Euclidean Algorithm: is a method for finding the GCD of two numbers.

Repeatedly subtract the the smaller number from the larger number until one of them becomes O. The other number that is left is the GCD.

n1=20, n2=15

gcd (20, 15) = gcd (20-15, 15) = god (5, 15)
gcd (5, 15) = gcd (15-5, 5) = gcd (10, 5)
gcd (10, 5) = gcd (10-5, 5) = gcd (5, 5)
gcd (5, 5) = gcd (5-5, 5) = gcd (0, 5) # 5 is the GCD

# Instead of subtracting both numbers, we will divide (get remainder) of large number modulo by small number, until one of them becomes zero, as it will reduce a lot of time.

gcd(20, 15) = gcd(5, 15) = god (5, 0) = 5
*/

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

// TC: O(log(min(a,b)))
// SC: O(1)