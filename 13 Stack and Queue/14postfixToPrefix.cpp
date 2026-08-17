#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string &s) {

    stack<string> st;

    for (int i = 0; i < s.size(); i++) {

        if (isalnum(s[i])) {
            
            st.push(string(1, s[i]));
        }
        else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = s[i] + op2 + op1; // # check the order

            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string s = "ABC/-AK/L-*";

    cout << postfixToPrefix(s);

    return 0;
}

// TC: O(n)
// SC: O(n)