#include <bits/stdc++.h>
using namespace std;

int sumOfSubarrayMinimums(vector<int> &arr) {

    int n = arr.size();

    vector<int> pse(n), nse(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] > arr[i]) { // # we didn't use = here but we used it in case of nse (to avoid overlap)
            st.pop();
        }

        if (st.empty()) { // distance until the current element is smallest
            pse[i] = i + 1;
        } else {
            pse[i] = i - st.top();
        }

        st.push(i);
    }

    // empty the stack
    while (!st.empty()) {
        st.pop();
    }

    for (int i = n-1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            nse[i] = n - i;
        } else {
            nse[i] = st.top() - i;
        }
        
        // push the current element's index onto the stack if its element is greater than index's element, on top of stack
        st.push(i);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {

        // contribution of current element
        result += arr[i] * pse[i] * nse[i];
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    cout << sumOfSubarrayMinimums(arr);

    return 0;
}

// TC: O(n)
// SC: O(n)