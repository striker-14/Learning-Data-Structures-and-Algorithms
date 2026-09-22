#include <bits/stdc++.h>
using namespace std;

int longestRepeatingCharacterReplacement(string &s, int k) {

    int n = s.size();

    unordered_map<char, int> freq;

    int maxFreq = 0;
    int res = 0;

    int l = 0, r = 0;

    while (r < n) {

        // increase the frequency of the current character
        freq[s[r]]++;

        // update maxFreq with the frequency of the most frequency character in the current window
        maxFreq = max(maxFreq, freq[s[r]]);

        // shrink the window if more than k changes required
        while (r - l + 1 - maxFreq > k) {
            freq[s[l]]--;
            l++;
        }

        // update the maximum length of the substring
        res = max(res, r - l + 1);

        // move right pointer
        r++;
    }

    return res;
}

int main() {
    string s = "ABABA";

    int k = 2;

    cout << longestRepeatingCharacterReplacement(s, k);

    return 0;
}

// TC: O(n)
// SC: O(1)