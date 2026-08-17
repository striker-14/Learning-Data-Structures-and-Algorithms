#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement2(vector<int> &arr) {

    int n = arr.size();
    vector<int> res(n, -1);
    
    stack<int> st;

    for (int i = 2*n-1; i >= 0; i--) { // first make sure the stack is once with all elements
        
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }

        // if stack is not empty, the top element is next greater element
        if (i < n && !st.empty()) {
            res[i] = st.top();
        }

        st.push(arr[i % n]);
    }

    return res;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {5, 7, 1, 2, 6};

    vector<int> result = nextGreaterElement2(arr);

    printArray(result);

    return 0;
}

// TC: O(n)
// SC: O(n)