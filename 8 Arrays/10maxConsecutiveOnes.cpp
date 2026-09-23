#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr) {

    int count = 0;
    int maxCount = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1};

    cout << maxConsecutiveOnes(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)