#include <bits/stdc++.h>
using namespace std;

int sumOfSubarrayRanges(vector<int> &arr) {

    int n = arr.size();

    vector<int> pse(n), nse(n);
    vector<int> pge(n), nge(n);

    stack<int> st;

    // pse
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) { // # didn't use = here (to avoid overlap)
            st.pop();
        }

        if (st.empty()) {
            pse[i] = i + 1;
        } else {
            pse[i] = i - st.top();
        }

        st.push(i);
    }

    // empty stack
    while (!st.empty()) {
        st.pop();
    }

    // nse
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            nse[i] = n - i;
        } else {
            nse[i] = st.top() - i;
        }

        st.push(i);
    }

    // empty stack
    while (!st.empty()) {
        st.pop();
    }

    // pge
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) { // # didn't use = here (to avoid overlap)
            st.pop();
        }

        if (st.empty()) {
            pge[i] = i + 1;
        } else {
            pge[i] = i - st.top();
        }

        st.push(i);
    }

    // empty stack
    while (!st.empty()) {
        st.pop();
    }

    // nge
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            nge[i] = n - i;
        } else {
            nge[i] = st.top() - i;
        }

        st.push(i);
    }

    // calculate total contribution
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        
        int maxContri = pge[i] * nge[i] * arr[i];

        int minContri = pse[i] * nse[i] * arr[i];

        totalSum += (maxContri - minContri);
    }

    return totalSum;
}

int main() {
    vector<int> arr = {1, 2, 3};

    cout << sumOfSubarrayRanges(arr);

    return 0;
}

// TC: O(n)
// SC: O(n)