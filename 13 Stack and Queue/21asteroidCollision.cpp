#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr) {

    vector<int> st;

    for (int i = 0; i < arr.size(); i++) {
        int element = arr[i];

        if (element >= 0) {
            st.push_back(element);
        }
        else {
            while (st.size() > 0 && st.back() >= 0 && abs(element) > st.back()) {
                st.pop_back();
            }

            if (st.size() > 0 && st.back() >= 0 && st.back() == abs(element)) {
                st.pop_back();
            }
            
            else if (st.size() == 0 || st.back() < 0) {
            st.push_back(element);
            }
        }
    }

    return st;
}

int main() {
    vector<int> arr = {10, -5, -8, 2, -5};

    vector<int> result = asteroidCollision(arr);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(n)