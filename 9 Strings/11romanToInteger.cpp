#include <bits/stdc++.h>
using namespace std;

int value(char r) {

    if (r == 'I') {
        return 1;
    }

    if (r == 'V') {
        return 5;
    }

    if (r == 'X') {
        return 10;
    }

    if (r == 'L') {
        return 50;
    }

    if (r == 'C') {
        return 100;
    }

    if (r == 'D') {
        return 500;
    }

    if (r == 'M') {
        return 1000;
    }

    return -1;
}

int romanToDecimal(string &s) {

    int res = 0;

    for (int i = 0; i < s.length(); i++) {

        int s1 = value(s[i]);

        // compare with the next symbol if it exists
        if (i + 1 < s.length()) {
            int s2 = value(s[i+1]);
        

            // if current value is greater or equal, add it to result
            if (s1 >= s2) {
                res += s1;
            } else {
                // else add the difference and skip the next symbol (means the one we are subtracting from, we treat two characters as one while subtracting
                res += (s2-s1);
                i++;
            }
        }
    }

    return res;
}

int main() {
    string s = "MIX";

    cout << romanToDecimal(s);

    return 0;
}

// TC: O(n)
// SC: (1)