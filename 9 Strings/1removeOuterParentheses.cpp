#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {

    int open_count = 0;
    int close_count = 0;
    string res = ""; // intializing empty string

    int start = 0;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '(') { // # used single quotes and not double because char values are always in single quotes
            open_count++;
        } else if (c == ')') {
            close_count++;
        }

        if (open_count == close_count) {
            res += s.substr(start + 1, i - start - 1); // substr() function is used to extract a substring from the given string
            // above we extracted what was between the parentheses excluding outer parentheses

            start = i + 1; // new value of start
        }
    }

    return res;
}

int main() {
    string s = "(()())(())()";
    cout << removeOuterParentheses(s);

    return 0;
}

// TC: O(n)
// SC: O(1)