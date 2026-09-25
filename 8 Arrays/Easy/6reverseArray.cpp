#include <bits/stdc++.h>
using namespace std;

// Using Two Pointers - O(n) Time and O(1) Space
void reverseArray(vector<int> &arr) { // # funcion does not return a value
    int left = 0;
    int right = arr.size()-1;

    while (left < right) {

        swap(arr[left], arr[right]);

        left++;

        right--;
    }
}

/*
// Using Recursion - O(n) Time and O(n) Space
void reverseArrayRec(vector<int> &arr, int left, int right) {

    if (left >= right) {
        return;
    }

    swap(arr[left], arr[right]);

    reverseArrayRec(arr, left + 1, right - 1);
}
*/

int main() {
    vector<int> arr = {1, 4, 3, 2, 6, 5};

    reverseArray(arr);

    // int left = 0;
    // int right = arr.size()-1;
    // reverseArrayRec(arr, left, right);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}