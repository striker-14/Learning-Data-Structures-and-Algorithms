/*
Searching in Array: The operation of finding a particular element or a group of elements in the array.

Linear Search: A sequential search algorithm that starts at one end and goes through each element of a list until the desired element or group of elements is found. Otherwise, the search continues till the end of the data set.

* This has a time complexity of O(n) where 'n' is the length of the array.

# If no element is equal to the target element, then return -1 as the element is not found.

# Linear Search is also known as sequential search.

When we have an unsorted array or list, linear search is most commonly used to find elements within the list.

Linear Search is preferred over Binary Search when we have small data sets.
*/

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int x) { // # arr is passed by reference (We are passing the actual variable itself, not a copy of it)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            return i;
        } // Didn't use else here otherwise it would have returned -1 for every value of arr[i] that is not equal to x
    }
    return -1; // If the loop fails then return -1
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10; // Key

    int result = linearSearch(arr, x);

    if (result == -1) {
        cout << "Not Present";
    } else {
        cout << "Present at index: " << result;
    }

    return 0;
}

// TC: O(n)
// SC: O(1)