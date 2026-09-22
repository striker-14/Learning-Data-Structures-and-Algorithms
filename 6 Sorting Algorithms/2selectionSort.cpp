/*
Selection Sort: Comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.

1. First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.

2. Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.

3. We keep doing this until we get all elements moved to correct position.
*/#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n) {

    for (int i = 0; i < n-1; i++) { // we run the loop till n-1 because last element gets already sorted till we reach it
        
        int min_idx = i; // set the current index as min and update it when you find min element, to min element

        for (int j = i+1; j < n; j++) { // we begin from i+1 because we start comparing from second element, till n (last element)

            if (arr[j] < arr[min_idx]) { // compared it with min_idx and not i because min_idx updates it value with every loop and we want to keep comparing until we find the minimum element among the remaining elements, not doing this will give us the first element that we found which is less than i and not the minimum
                min_idx = j; // update min index to min element
            }
        }

        swap(arr[i], arr[min_idx]); // when loop has ended and you have figured out which element is min, swap it with i
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    selectionSort(arr, n);

    printArray(arr);

    return 0;
}

// TC: O(n^2)
// SC: O(1)