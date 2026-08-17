#include <bits/stdc++.h>
using namespace std;

int consecutiveSequence(vector<int> &arr) {

    int res = 0;

    unordered_set<int> st; // set not map
    for (int num : arr) {; // hash all array elements
        st.insert(num);
    }

    for (int num : arr) {

        if (st.find(num) != st.end() && st.find(num-1) == st.end()) { // num is the starting index or not (num-1 doesn't exist in the array)
            // st.end() is equal to "not found/past the last element"

            int curr = num;
            int count = 0;

            while (st.find(curr) != st.end()) {
                
                st.erase(curr); // remove the number to avoid recomputation
                curr++;
                count++;
            }

            res = max(res, count);
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};

    cout << consecutiveSequence(arr);

    return 0;
}

// TC: O(n) // because while loop erases elements
// SC: O(n)