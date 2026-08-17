#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &arr, int k) {

    vector<int> res;
    deque<int> dq(k); // of size k

    // process first k (or first window) elements of array
    for (int i = 0; i < k; i++) {

        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // process rest of the elements from arr[k] to arr[n-1]
    for (int i = k; i < arr.size(); i++) {

        res.push_back(arr[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    res.push_back(arr[dq.front()]);

    return res;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 3, 2, 1, 7, 3};

    int k = 3;

    vector<int> result = slidingWindowMaximum(arr, k);

    printArray(result);

    return 0;
}

// TC: O(n)
// SC: O(k)