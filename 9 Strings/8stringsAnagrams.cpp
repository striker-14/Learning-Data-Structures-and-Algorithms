#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string &s1, string &s2) {

    if (s1.size() != s2.size()) {
        return false;
    }

    // create a hashmap to store character frequencies
    unordered_map<char, int> mp;

    // count frequency of each character in s1
    for (int i = 0; i < (int)s1.size(); i++) {
        char ch = s1[i];
        mp[ch]++;
    }

    // subtract for s2;
    for (int i = 0; i < (int)s2.size(); i++) {
        char ch = s2[i];
        mp[ch]--;
    }

    // check if all frequencies are zero
    for (auto &pair : mp) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";

    cout << areAnagrams(s1, s2);

    return 0;
}

// TC: O(n+m)
// SC: O(1)