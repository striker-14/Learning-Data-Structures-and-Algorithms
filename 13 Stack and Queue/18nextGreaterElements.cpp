#include <bits/stdc++.h>
using namespace std;

int numberofnges(vector<int> &arr, int index) {

    int count = 0;
    int n = arr.size();

    for (int i = index + 1; i < arr.size(); i++) {
        if (arr[i] > arr[index]) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};

    int Q = 2;
    vector<int> queries = {0, 5};

    for (int i = 0; i < Q; i++) {
        // function call
        cout << numberofnges(arr, queries[i]) << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(1)