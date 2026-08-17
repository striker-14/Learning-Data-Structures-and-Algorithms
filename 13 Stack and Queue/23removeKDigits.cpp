#include <bits/stdc++.h>
using namespace std;

string removeKDigits(string &s, int k) {

    int n = s.size();
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        // remove larger digits
        while (!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k--;
        }

        if (!st.empty() || c != '0') {
            st.push(c);
        }
    }

    // remove remaining elements if any
    while (!st.empty() && k) {
        st.pop();
        k--;
    }

    if (st.empty()) {
        return "0";
    }

    // Build result from stack
    while (!st.empty()) {
        s[n-1] = st.top();
        st.pop();
        n--;
    }

    return s.substr(n); // return the substring of s starting from n
    // starting from n because while building result from stack, n now points to the first valid digit
}

int main() {
    string s = "765028321";

    int k = 5;

    cout << removeKDigits(s, k);

    return 0;
}

// TC: O(n)
// SC: O(n)