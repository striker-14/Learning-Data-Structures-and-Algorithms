#include <bits/stdc++.h>
using namespace std;

int substringsThreeCharacters(string &s) {

    vector<int> freq(3, 0); // all 3 elements are initialized to 0

    int res = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {

        freq[s[right] - 'a']++;

        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

            res += (s.size() - right);

            freq[s[left] - 'a']--;
            left++;
        }
    }

    return res;
}

int main() {
    string s = "abcabc";

    cout << substringsThreeCharacters(s);

    return 0;
}

// TC: O(n)
// SC: O(1) // freq only stores 3 elements no matter the size of array