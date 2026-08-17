#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(string &s, int k) {

    unordered_map<char, int> freq;

    int maxLen = 0;

    int left = 0;

    for (int right = 0; right < s.size(); right++) {

        freq[s[right]]++;

        // if number of key-value pairs in the map exceeds k, remove frequency from left
        while (freq.size() > k) { // # .size() in unordered_map returns the number of key-value pairs currently stored in the map
            freq[s[left]]--;
            
            // after removing, when the frequency of character becomes zero, erase from the map
            if (freq[s[left]] == 0) {
            freq.erase(s[left]);
            }      
            // move left pointer ahead     
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "eceba";

    int k = 2;

    cout << atMostKDistinct(s, k);

    return 0;
}

// TC: O(n)
// SC: O(k) // at any time the map contains at most k distinct characters because of while condition (while (freq.size() > k))