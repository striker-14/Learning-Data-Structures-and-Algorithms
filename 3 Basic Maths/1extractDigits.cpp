/*
Q1. Extract digits from a given number.
Given a positive integer n, prints the digits of n separately.
*/ 

#include <bits/stdc++.h>
using namespace std;

vector<int> extractDigits(int n) { // we use vector to declare vector function because we are storing the ans in vector and returning it which can be done in vector only
    vector<int> ans; // to store the digits getting extracted at each step

    while (n > 0) {
        int lastDigit = n % 10; // # When we take modulus of a number by 10 (7789 % 10) we get the last digit
        ans.push_back(lastDigit); // push the extracted digit into the vector
        n = n / 10;
    }

    reverse(ans.begin(), ans.end()); // to reverse the elements as they were stored from last to first

    return ans;
}

int main() {
    int n = 7789;
    vector<int> digits = extractDigits(n); // vector to get extracted digits
    for (auto num : digits) {
        cout << num << " ";
    }
    return 0;
}

// TC: O(log n) // divided by 10 at each step
// SC: O(log n) // every time you multiply by 10 you just add ONE digit. Digits are not n number of but the number of times the number is divided until it becomes 0