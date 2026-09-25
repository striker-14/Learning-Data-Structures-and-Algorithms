/*
Q9. Print array after it is right rotated d time (# right elements will change position)

# The idea is to reverse the array three times. For the first time we reverse only the last d elements. Second time we will reverse the first (n-d) elements. Finally we will get our rotated array by reversing the entire array
*/

#include <bits/stdc++.h>
using namespace std;

void rightRotateD(vector<int> &arr, int n, int d) {

    d %= n;

    reverse(arr.begin()+n-d, arr.end());

    reverse(arr.begin(), arr.begin()+n-d);

    reverse(arr.begin(), arr.end());
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int d = 2;

    rightRotateD(arr, n, d);

    printArray(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)