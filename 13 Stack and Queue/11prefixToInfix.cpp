#include <bits/stdc++.h>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x) {
    switch(x) {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '%':
        return true;
    }
    return false;
}

string prefixToInfix(string s) {

    stack<string> st; // of string type

    // reading from right to left
    for (int i = s.size()-1; i >= 0; i--) {

        if (isOperator(s[i])) {

            // pop two operands from stack
            string op1 = st.top(); 
            st.pop();
            string op2 = st.top(); 
            st.pop();

            // concat the operands and the operator
            string temp = "(" + op1 + s[i] + op2 + ")";

            // push string temp back to stack
            st.push(temp);
        }

        // if symbol is an operand
        else {

            // push the operand to the stack
            st.push(string(1, s[i])); // push the operand to the stack string(1, pre_exp[i]) constructs a string of length 1 whose only character is pre_exp[i] (this is calling the string(size, character) constructor).
        }
    }

    // stack now contains the infix expression
    return st.top();
}

int main() {
    string s = "*-A/BC-/AKL";

    cout << prefixToInfix(s);

    return 0;
}

// TC: O(n)
// SC: O(n)