#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string &s1, string &s2) {

    unordered_map<char, int> m1, m2;

    for (int i = 0; i < s1.size(); i++) {

        // is character not seen before, store its first occurrence index
        if (m1.find(s1[i]) == m1.end()) {
            m1[s1[i]] = i;
        }

        if (m2.find(s2[i]) == m2.end()) {
            m2[s2[i]] = i;
        }

        // check if the first occurrence indices match
        if (m1[s1[i]] != m2[s2[i]]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1 = "aab";
    string s2 = "xxy";

    if (areIsomorphic(s1, s2)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}

// TC: O(n)
// SC: O(1)