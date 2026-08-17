#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr) {
    
    int n = arr.size(); // we should declare n here otherwise the below vector won't work
    vector<int> res(n, -1); // declare a vector of integers named res, its size is n, every element is initialized to -1

    stack<int> st;

    for (int i = n-1; i >= 0; i--) {

        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // if stack is not empty, the top element is the next greater element
        if (!st.empty()) {
            res[i] = st.top();
        }

        // push the current element onto the stack
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
    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> result = nextGreaterElement(arr);

    printArray(result);

    return 0;
}

// TC: O(n)
// SC: O(n)