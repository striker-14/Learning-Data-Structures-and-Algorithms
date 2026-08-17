#include <bits/stdc++.h>
using namespace std;

void frequencyArray(int arr[], int n) {

    unordered_map<int, int> um;

    for (int i = 0; i < n; i++) {
        um[arr[i]]++; // Increment the frequency of element by 1 in the unordered map
    }

    for (auto num : um) {
        cout << num.first << "->" << num.second << endl;
    }
}

int main() {
    int arr[] = {10, 20, 10, 5, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    frequencyArray(arr, n);

    return 0;
}

// TC: O(n)
// SC: O(n)