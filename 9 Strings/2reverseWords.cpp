#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

    int n = s.size();
    string res = ""; // intialize empty result string to store result

    // first reverse the complete string
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        string word = "";

        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if (word.size() > 0) {
            res += " " + word;
        }
    }

        return res.substr(1); // # to remove the extra space that we added while adding word to res (because when the add the first word it also adds space to res)
        // substr(1) begins extracting substring from index 1
}

int main() {
    string s = "the pen";
    
    cout << reverseWords(s);

    return 0;
}

// TC: O(n) // even though there are two loops (one inside the another) but they are both incrementing i so we iterate one word only once
// SC: O(1)