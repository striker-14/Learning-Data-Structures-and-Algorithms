#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string &s) {

    stack<string> st;

    for (int i = 0; i < s.size(); i++) {
        
        if (isalnum(s[i])) {
            
            st.push(string(1, s[i]));
        }
        else { // if it is an operator
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = "(" + op2 + s[i] + op1 + ")"; // # op2 comes first in postfix to infix
            st.push(temp);
        }
    }
    // There must be a single element in the stack now which is the required infix
    return st.top();
}

int main() {
    string s = "ab*c+";

    cout << postfixToInfix(s);

    return 0;
}

// TC: O(n)
// SC: O(n)