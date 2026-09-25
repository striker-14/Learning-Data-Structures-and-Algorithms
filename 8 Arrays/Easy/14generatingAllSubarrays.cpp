/*
Input: arr[] = {1, 2, 3}
Output: [1], [2], [3], [1, 2], [2, 3], [1, 2, 3]

# For an array of size n, there are (n*(n+1))/2 non-empty subarrays.

Iterative Approach - O(n^3) Time and O(1) Space

Outermost Loop: Picks starting index of current subarray

Middle Loop: Picks ending index of current subarray

Innermost Loop: Prints the subarray from the starting index to the ending index
*/

#include <bits/stdc++.h>
using namespace std;

void subArray(vector<int> &arr) {

    int n = arr.size();

    // Pick starting point
    for (int i = 0; i < n; i++) {

        // Pick ending point
        for (int j = i; j < n; j++) {

            // Print subarray between current starting and ending points
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

/*
Recursive Approach - O(n^3) Time and O(n) Space

We use two pointers start and end to maintain the starting and ending point of the array and follow the steps given below:

- Stop if we have reached the end of the array.

- Increment the end index if start has become greater than end.

- Print the subarray from index start to end and increment the starting index.

void subArray(vector<int> &arr, int start, int end) {

    // Stop if we have reached the end of the array
    if (end == arr.size()) {
        return;
    }

    // Increment the end point and reset the start to 0
    else if (start > end) {
        subArray(arr, 0, end+1);
    }

    // Print the subarray and increment the starting point
    else {
        for (int i = start; i <= end; i++) {
            cout << arr[i] << " ";
        }
        subArray(arr, start+1, end);
    }
}
*/

int main() {
    vector<int> arr = {1, 2, 3, 4};

    cout << "All non-empty subarrays" << endl;

    subArray(arr);

    return 0;
}

// TC: O(n^3)
// SC: O(1)