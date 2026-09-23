#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr) {

    int n = arr.size();

    int candidate = -1;
    int count = 0;

    for (int num : arr) {
        if (count == 0) { // if count becomes zero change the element
            candidate = num; // set candidate to current element
        }
        else if (num == candidate) { // increment the count
            count++;
        }
        else {
            count--; // if not equal to candidate
        }
    }

    count = 0; // again set the count to 0
    for (int num : arr) { // count the number of occurrences of candidate
        if (num == candidate) {
            count++;
        }
    }

    if (count > n/2) {
        return candidate;
    }
    else {
        return -1;
    }
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};

    cout << majorityElement(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)