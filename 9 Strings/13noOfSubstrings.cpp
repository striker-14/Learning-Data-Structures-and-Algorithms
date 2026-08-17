#include <bits/stdc++.h>
using namespace std;

int countOfSubstrings(string &s) {

    int n = s.length();

    return n*(n+1)/2;
}

int main() {
    string s = "abcde";

    cout << countOfSubstrings(s);

    return 0;
}

// TC: O(1)
// SC: O(1)