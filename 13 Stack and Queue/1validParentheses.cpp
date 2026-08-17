#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string &s) {

    stack<char> st; // # declared stack as char but input s is of string type

    for (char c : s) {

        if (c == '(' || c == '{' || c == '[') { // # single brackets because they are of char type
            st.push(c);
        }

        else if (c == ')' || c == '}' || c == ']') {
            // first check if stack is empty or not (no element got in there)
            if (st.empty()) {
                return false;
            }
        
            char top = st.top();
            
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                    return false;
            }

            // pop matching element from the stack
            st.pop();
        
        }
    }

    // balanced if stack is empty
    return st.empty();
}

int main() {
    string s = "[()()]{}";

    cout << (isBalanced(s) ? "true" : "false");

    return 0;
}

// TC: O(n)
// SC: O(n) // in the worst case the stack will store all opening brackets in the string s that only contains opening brackets