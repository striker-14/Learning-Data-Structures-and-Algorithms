/*
Insertion Sort Algorithm: A simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position of the list.

It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

1. We start with second element of the array, as first element in the array that is assumed to be sorted.

2. Compare second element with the first element and check if the second element is smaller, then swap them.

3. Move to the third element and compare it with the first two elements and put it in its correct position.

4. Repeat until the entire array is sorted.
*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n) {

    for (int i = 1; i < n; i++) { // we begin from second element (assume first element is already sorted)

        int x = arr[i]; // key (element). The element to be placed in correct position. We don't care what happens to the element's current position that's why we are already storing its value in x. Also to compare it with other elements

        int j = i-1; // start comparing from one element less than the current element

        while (j >= 0 && arr[j] > x) { // Iterate untill j becomes negative. Also no need to check further if the current j element is less than x, as the remaining elements will also be less than x because they were also previously sorted
            arr[j+1] = arr[j]; // move j one position further to leave space for the element smaller than current j
            j--; // reduce the value of j on every iteration to cover all elements
        }
        
        // j+1 is the empty space (not really) as the element at that position got shifted one position further
        arr[j+1] = x; // # With reduced j value // once you have found the element which is smaller than x (key), place x one position after that element in the empty space (not really). # We didn't swap here because the element at x (i position) would have changed after so much iterations, as we had already stored the value of x (key), we simply place it in the correct position
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    insertionSort(arr, n);

    printArray(arr);

    return 0;
}

// TC: O(n^2) Best Case: O(n) (when array is already sorted)
// SC: O(1)