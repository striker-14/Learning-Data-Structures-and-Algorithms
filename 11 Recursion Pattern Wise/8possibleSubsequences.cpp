#include <bits/stdc++.h>
using namespace std;

void possibleSubsequences(int i, string s, string &f) {

    if (i == s.length()) {
        cout << f << " ";
        return;
    }

    // picking
    f = f + s[i];
    possibleSubsequences(i+1, s, f);
    // popping out while backtracking
    f.pop_back();
    possibleSubsequences(i+1, s, f);
}

int main() {
    string s = "abc";

    string f = " ";

    possibleSubsequences(0, s, f);

    return 0;
}

// TC: O(2^n)
// SC: O(n)