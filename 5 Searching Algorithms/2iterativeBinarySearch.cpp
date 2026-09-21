/*
Binary Search: is a searching algorithm used in a sorted array. In this algorithm, the element is found by repeatedly dividing the search interval in half and deciding the next interval to find the element.

Has a time complexity of O(log n) where 'n' is the length of the array.

# The only thing to note is that the array must be sorted in increasing or decreasing order.

Binary Search Algorithm:

1. Divide the search space into two halves by finding the middle index 'mid'.

2. Compare the middle element of the search space with the key.

3. If the key is found at middle element, the process is terminated.

4. If the key is not found at middle element, choose which half will be used as the next search space.
   
   - If the key is smaller than the middle element, then the left side is used for next search.

   - If the key is larger than the middle element, then the right side is used for next search.

5. This process is continued until the key is found or the total search space is exhausted.


Iterative Binary Search Algorithm: Here we use a while loop to continue the process of comparing the key and splitting the search space in two halves.
*/

#include <bits/stdc++.h>
using namespace std;

int iterativeBinarySearch(vector<int> &arr, int x, int low, int high) {

    while (low <= high) { // Ensures that there are still elements to search through (also includes the case when low = high). The search space gets exhausted. The low moves right, high moves left, they cross each other
        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            return mid;
        }

        if (x < arr[mid]) { // Choose left half if key is less than middle element not mid (which is index)
            high = mid - 1; // reduce the search space to element on left of mid (# we already checked mid)
        } else {
            low = mid + 1;
        }
    }

    return -1; // If we reach here then element was not present in the array

}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;

    int low = 0;
    int high = arr.size() - 1; // We do minus 1 because size() return the number of elements but we need to set high as index of last element

    int result = iterativeBinarySearch(arr, x, low, high);

    if (result == -1) {
        cout << "Not Present";
    } else {
        cout << "Present at index: " << result;
    }

    return 0;
}

// TC: O(log n) // as we are repeatedly dividing the array
// SC: O(1)