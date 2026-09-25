/*
Q7. Rotate an array by d places - Counterclockwise or Left (# left elements will change position)

Input: arr[] = {1, 2, 3, 4, 5, 6}, d=2
Output: {3, 4, 5, 6, 1, 2}

Using Reversal Algorithm - O(n) Time and O(1) Space

# The idea is based on the observation that if we left rotate the array by d positions, the last (n-d) elements will be at the front and the first d elements will be at the end

1. Reverse the subarray containing the first d elements of the array.

2. Reverse the subarray containing the last (n-d) elements of the array.

3. Finally, reverse all the elements of the array.
*/

#include <bits/stdc++.h>
using namespace std;

void leftRotateD(vector<int> &arr, int n, int d) {

    // handles the case when d > n (size of array)
    d %= n; // rotating an array of size 6 by 8 places is same as rotating it by 2 places

    // reverse the first d elements
    reverse(arr.begin(), arr.begin()+d); // arr.begin()+d doesn't include itself element but still does the work because of indexing (0, 0+2)

    // reverse the remaining n-d elements
    reverse(arr.begin()+d, arr.end()); // arr.end() points to one position after the last element

    // reverse the whole array
    reverse(arr.begin(), arr.end());
}

void printArray(vector<int> &arr) {
    for (auto num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int d = 2;

    leftRotateD(arr, n, d);

    printArray(arr);

    return 0;
}

// TC: O(n) // it is 2n as we are visiting each element exactly twice which is same as n
// SC: O(1)