#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n) {

    int originalNumber = n; // we store this number in the beginning only because n changes in the later steps
    int reversedNumber = 0;

    while (n > 0) {
        int lastDigit = n % 10;
        reversedNumber = (reversedNumber * 10) + lastDigit;
        n = n / 10;
    }

    if (originalNumber == reversedNumber) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n = 4554;
    if (isPalindrome(n)) {
        cout << n << " is a palindrome";
    } else {
        cout << n << " is not a palindrome";
    }

    return 0;
}