#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> &arr) {

    int n = arr.size();

    vector<int> span(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }

        st.push(i);
    }

    return span;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 80};

    vector<int> result = stockSpan(arr);

    printArray(result);

    return 0;
}

// TC: O(n)
// SC: O(n)