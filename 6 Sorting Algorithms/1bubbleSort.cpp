/*
Array Sorting: Sorting an array means arranging the elements of the array in a certain order. Generally sorting in an array is done to arrange the elements in increasing or decreasing order.

- In-place Sorting: Uses constant space for producing the output (modifies the given array only).

- Internal Sorting: When all data is placed in the main memory or internal memory. The problem cannot take input beyond allocated memory size.

- External Sorting: When all the data that needs to be sorted need not be placed in memory at a time. Used for massive amount of data.

- Stable Sorting: When two same items appear in the same order in sorted data as in original array.

- Hybrid Sorting: If it uses more than one standard sorting algorithms to sort the array. The idea is to take advantage of multiple sorting algorithms.


Type of Sorting Techniques:

1. Comparision-based: We compare the elements in a comparison-based sorting algorithm.
Bubble, Insertion, Selection, Quick, Merge, Heap

2. Non-comparison-based: We do not compare the elements in a non-comparison-based sorting algorithm.
Counting, Radix


Bubble Sort Algorithm: is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.

# This algorithm is not suitable for large datasets as its average and worst-case time complexity are quite high.

1. We sort the array using multiple passes. After the first pass, the maximum element goes to end (its correct position). Same way, after second pass, the second largest element goes to second last position and so on.

2. In every pass, we process only those elements that have already not moved to correct position. After k passes, the largest k element must have been moved to the last k positions.

3. In a pass, we consider remaining elements and compare all adjacent and swap if larger element is before a smaller element. If we keep doing this, we get the largest (among the remaining elements) at its correct position.


# In-Place Algorithm: is an algorithm that does not need an extra space and produces an output in the same memory that contains the data.
*/

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {

    bool swapped; // boolean to check if swapping happened or not

    for (int i = 0; i < n-1; i++) { // we iterate i till n-1 (goes till second last) (to prevent accessing arr[j+1] out of bounds in the inner loop)
        
        swapped = false;

        for (int j = 0; j < n-1-i; j++) { // we iterate j till n-i-1 because after each pass(i), element (among remaining) at the end gets sorted
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true; // set it as true as swapping is taking place
            }
        }

        if (!swapped) { // Swapping is not taking place (means array is already sorted), so break out of OUTER loop
            break;
        }
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    bubbleSort(arr, n);

    printArray(arr);

    return 0;
}

// TC: O(n^2)
// SC: O(1) 