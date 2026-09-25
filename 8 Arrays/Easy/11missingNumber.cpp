/*
Given an integer N and an array of size (N-1) containing (N-1) numbers between 1 to N. Find the number (between 1 to N), that is not present in the given array.
*/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int n) {

    int sumOfN = (n*(n+1))/2; // sum of natural numbers

    int sumOfArray = 0; // you have to declare it to 0 (not just declare it)

    for (int i = 0; i < n-1; i++) { // till n-1 because one element is missing
        sumOfArray += arr[i];
    }

    int number = sumOfN - sumOfArray;

    return number;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 4, 5};

    int n = 5; // given

    cout << missingNumber(arr, n);

    return 0;
}

// TC: O(n)
// SC: O(1)