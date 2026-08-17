#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr) {

    int n = arr.size();

    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            res[i] = st.top();
        }

        // push current element onto the stack
        st.push(arr[i]);
    }

    return res;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    vector<int> result = previousSmallerElement(arr);

    printArray(result);

    return 0;
}

// TC: O(n)
// SC: O(n)