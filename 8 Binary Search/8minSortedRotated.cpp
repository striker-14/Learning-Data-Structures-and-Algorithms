#include <bits/stdc++.h>
using namespace std;

int minSortedRotated(vector<int> &arr) {

    int low = 0, high = arr.size()-1;

    while (low < high) { // low cannot be equal to high (when low == high were're done, both pointers point to the same element which is minimum element)

        if (arr[low] < arr[high]) { // if array is already sorted
            return arr[low];
        }

        // we reach here it there are atleast two elements and array is rotated
        int mid = low + (high - low)/2;

        if (arr[mid] > arr[high]) { // if right half is not sorted so the minimum element must be in the right half
            low = mid + 1;
        }

        // if right half is sorted, but we won't make high = mid - 1, because mid can also be minimum because we are going in opposite direction
        else {
            high = mid;
        }
    }

    return arr[low];
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    
    cout << minSortedRotated(arr);

    return 0;
}

// TC: O(log n)
// SC: O(1)