#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElementIndexes(vector<int> &arr) {

    int n = arr.size();

    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            pse[i] = st.top();
        }

        // push current index onto the stack
        st.push(i); // we are storing indexes not values itself
    }

    return pse;
}

vector<int> nextSmallerElementIndexes(vector<int> &arr) {

    int n = arr.size();

    vector<int> nse(n, n); // use n here because you need a boundary
    stack<int> st;

    for (int i = n-1; i >= 0; i--) {

        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top();
        }

        // push current element onto the stack
        st.push(i);
    }

    return nse;
}

int largestRectangularArea(vector<int> &arr) {

    vector<int> pse = previousSmallerElementIndexes(arr);
    vector<int> nse = nextSmallerElementIndexes(arr);

    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++) {

        int width = nse[i] - pse[i] - 1;

        int area = arr[i] * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};

    cout << largestRectangularArea(arr);

    return 0;
}

// TC: O(n)
// SC: O(n)