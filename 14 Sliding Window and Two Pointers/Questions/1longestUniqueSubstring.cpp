#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string &s) {

    if (s.length() == 0 || s.length() == 1) {
        return s.length();
    }

    int res = 0;
    vector<bool> vis(26, false); // intializes all 26 entries to false

    int left = 0, right = 0;

    while (right < s.length()) {

        while (vis[s[right] - 'a'] == true) { // this character is already present in the current window

            vis[s[left] - 'a'] = false; // marks the character at position left as "no longer in the window"
            left++;
        }

        vis[s[right] - 'a'] = true; // after the loop ends, s[right] is no longer in the window
        // marks this character as now included in the updated window

        // length of the curretn window
        res = max(res, (right - left + 1));
        
        right++;
    }

    return res;
}

int main() {
    string s = "geeksforgeeks";

    cout << longestUniqueSubstring(s);

    return 0;
}

// TC: O(n)
// SC: O(1)