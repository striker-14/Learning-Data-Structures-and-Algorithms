#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string s) {
    if (i >= s.size()/2) {
        return true;
    }

    if (s[i] != s[s.size() - i - 1]) {
        return false;
    } else {
        return isPalindrome(i + 1, s);
    }
}

int main() {
    string s = "MADAM";

    int i = 0;

    cout << isPalindrome(i, s);

    return 0;
}

// TC: O(n)
// SC: O(n) // due to recursive call stack