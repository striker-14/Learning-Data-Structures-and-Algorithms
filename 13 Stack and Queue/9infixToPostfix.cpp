#include <bits/stdc++.h>
using namespace std;

// function to return precedence of operators
int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

// function to check if operator is right-associative
bool isRightAssociative(char c) {
    return c == '^';
}

string infixToPostfix(string &s) {

    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        // if operand, add to result
        if ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {
                
            res += c;
        }

        // if '(', push to stack
        else if (c == '(') {
            st.push(c);
        }

        // if ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); // to remove '(' also from the stack because we don't want brackets
        }

        // if operator
        else {
            while (!st.empty() && st.top() != '(' && (prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && !isRightAssociative(c)))) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;

}

int main() {
    string s = "a*(b+c)/d";

    cout << infixToPostfix(s);

    return 0;
}

// TC: O(n)
// SC: O(n)