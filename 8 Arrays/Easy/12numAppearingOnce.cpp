/*
Q. Find the number that appears once, and the other numbers twice.

- XOR of two same numbers is always 0 i.e. a ^ a = 0
- XOR of a number with 0 is the number itself i.e. 0 ^ a = a

Here all numbers except the single number appear twice and so they will form a pair. Now, if we perform XOR of all elements of the array, the XOR of each pair will result in 0. The result will be 0 ^ (single number) = single number
*/

#include <bits/stdc++.h>
using namespace std;

int numAppearingOnce(vector<int> &arr) {

    int xorr = 0; // xor is a reserved keyword (xor = ^)

    for (int i = 0; i < arr.size(); i++) {
        xorr = xorr ^ arr[i];
    }

    return xorr;
}

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};

    cout << numAppearingOnce(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)