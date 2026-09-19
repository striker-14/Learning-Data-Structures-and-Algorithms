/*
Q3. Reverse a number.
Note: If a number has trailing zeros then its reverse will not include them. Eg:- reverse of 10400 will be 401 instead of 00401.

# Reason we didn't use vector here to store the extracted digits is because that if we were to do modulo of a number which has trailing zeros, it will also include those zeros in the answer and we don't want that. That's why we use another variable to store the digits which multiplies the already stored number in it by 10 to make space for the next number, and if we were to add zero as the first number, it will keep giving us zero and the zero won't get stored in the answer.

0 X 10 + 0 = 0
0 X 10 + 0 = 0
0 X 10 + 4 = 4
4 X 10 + 0 = 40
40 X 10 + 1 = 401
*/ 

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