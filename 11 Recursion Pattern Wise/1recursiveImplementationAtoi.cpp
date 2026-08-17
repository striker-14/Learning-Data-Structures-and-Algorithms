#include <bits/stdc++.h>
using namespace std;

int recursiveatoi(string &s, int n) {

    int count = 0;

    for (int i = 0; i < n; i++) {

        if (isalpha(s[i])) { // to check whether a character is an alphabet
            count++;
        }
    }

    if (count != 0) {
        return 0;
    }

    // if only one digit
    if (n == 1) {
        return s[0] - '0'; // converting character digit to integer
    }

    // if more than 1 digits, recur for (n-1), multiply result with 10 and add last digit
    return (10 * recursiveatoi(s, n-1) + s[n-1] - '0');
}

int main() {
    string s = "112";

    int n = s.size();

    cout << recursiveatoi(s, n);

    return 0;
}

// TC: O(n)
// SC: O(n)