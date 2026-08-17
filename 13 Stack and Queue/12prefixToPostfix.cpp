#include <bits/stdc++.h>
using namespace std;

// function to check if character is an operator or not
bool isOperator(char x) {
    switch(x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string prefixToPostfix(string &s) {

    stack<string> st;

    for (int i = s.size()-1; i >= 0; i--) {

        // check is symbol is operator
        if (isOperator(s[i])) {

            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + s[i];

            st.push(temp);
        }
        // if symbol is an operand
        else {
            st.push(string(1, s[i]));
        }
    }

    return st.top();
}

int main() {
    string s = "*-A/BC-/AKL";

    cout << prefixToPostfix(s);

    return 0;
}

// TC: O(n)
// SC: O(n)