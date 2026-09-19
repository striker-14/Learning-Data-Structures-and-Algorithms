/*
Q6. Check if a number is Armstrong number or not.
Armstrong Number: is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

Input: n = 153
Output: True
Explanation: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
*/

#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {

    int originalNumber = n; // to compare it with the sum of digits
    int sum = 0; // to store the cubic sum of all digits in the number

    while (n > 0) {
        int lastDigit = n % 10;

        sum = sum + pow(lastDigit, 3); // same as (lastDigit*lastDigit*lastDigit)

        n = n / 10;
    }

    if (originalNumber == sum) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n = 153;
    if (isArmstrong(n)) {
        cout << n << " is an armstrong number";
    } else {
        cout << n << " is not an armstrong number";
    }

    return 0;
}

// TC: O(log n)
// SC: O(1) // sum variable is used