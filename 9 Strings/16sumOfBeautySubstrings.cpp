#include <bits/stdc++.h>
using namespace std;

int sumOfBeautySubstrings(string &s) {

    int n = s.length();
    int sum = 0;

    // iterate over all substrings
    for (int i = 0; i < n; i++) {

        unordered_map<char, int> freq;

        for (int j = i; j < n; j++) {
            // increase frequency of current character
            freq[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for (auto it : freq) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }

            // add the difference to the sum
            sum += (maxi - mini); // because we need the total beauty of all substrings not just one that's why we keep adding
        }
    }

    return sum;
}
            

int main() {
    string s = "aaac";

    cout << sumOfBeautySubstrings(s);

    return 0;
}

// TC: O(n^2)
// SC: O(1)