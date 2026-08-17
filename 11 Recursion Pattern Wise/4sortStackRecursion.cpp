#include <bits/stdc++.h>
using namespace std;

// Insert elements into sorted stack
void sortedInsert(stack<int> &st, int x) {

    // if stack is empty or top element is smaller, push x
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return; // return here after one element is pushed
    }

    int top = st.top();
    st.pop();

    // recursively insert x in sorted order
    sortedInsert(st, x);

    st.push(top);
}

// Sort the stack recursively 
void sortStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }

    int top = st.top();
    st.pop();

    // recursively sort the remaining stack
    sortStack(st);

    sortedInsert(st, top);
}

int main() {
    stack<int> st;

    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

// TC: O(n^2)
// SC: O(n)