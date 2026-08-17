#include <bits/stdc++.h>
using namespace std;

int iterativeBinarySearch(vector<int> &arr, int x, int low, int high) {

    while (low <= high) { // Ensures that there are still elements to search through (also includes the case when low = high). The search space gets exhausted. The low moves right, high moves left, they cross each other
        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            return mid;
        }

        if (x < arr[mid]) { // Choose left half if key is less than middle element not mid (which is index)
            high = mid - 1; // reduce the search space to element on left of mid // we already checked mid
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