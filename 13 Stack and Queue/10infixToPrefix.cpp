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

// function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string s) {

    stack<char> st;
    string res;

    for (int i = s.size()-1; i >= 0; i--) {

        char c = s[i];

        if (isalnum(c)) { // is alphanumeric (a letter or a digit)
            res += c;
        }

        else if (c == ')') {
            st.push(c);
        }

        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }

        else if (isOperator(c)) {
            while (!st.empty() && isOperator(st.top()) && (prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && isRightAssociative(c)))) {
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

    // reverse at the end to get correct prefix
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s = "a*(b+c)/d";

    cout << infixToPrefix(s);

    return 0;
}

// TC: O(n)
// SC: O(n)