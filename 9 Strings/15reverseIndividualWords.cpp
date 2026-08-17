#include <bits/stdc++.h>
using namespace std;

string reverseIndividualWords(string &s) {

    stack<char> st;
    string res = "";

    for (int i = 0; i < s.size(); i++) {

        if (s[i] != ' ') {
            st.push(s[i]);
        } else {
            while (!st.empty()) { // while st (stack) doesn't become empty
                res += st.top();
                st.pop();
            }
            res += " "; // add space after the word
        }
    }

    // reverse the last word (because it doesn't end with space), so we need to manually empty it
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string s = "Geeks for Geeks";

    cout << reverseIndividualWords(s);

    return 0;
}

// TC: O(n)
// SC: O(n)