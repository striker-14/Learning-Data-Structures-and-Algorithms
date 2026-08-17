#include <bits/stdc++.h>
using namespace std;

int countAndMerge(vector<int> &arr, int l, int m, int r) {

    // counts in two subarrays
    int n1 = m-l+1, n2 = r-m;

    // set up two vectors for left and right halves
    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l+i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[m+1+j];
    }

    // intialize inversion count and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {

        if (left[i] <= right[j]) {
            arr[k] = left[i];
            k++;
            i++;
        } else {
            arr[k] = right[j];
            k++;
            j++;
            res += (n1-i); // right is smaller than n1-i because left[] is sorted
        }
    }

    // merge remaining elements
    while (i < n1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = right[j];
        k++;
        j++;
    }

    return res;
}

int countInversions(vector<int> &arr, int l, int r) {

    int res = 0;
    if (l < r) {
        int m = l + (r-l)/2;

        // recursively count inversions in left and right halves
        res += countInversions(arr, l, m);
        res += countInversions(arr, m+1, r);

        res += countAndMerge(arr, l, m, r);
    }

    return res;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    int n = arr.size();

    cout << countInversions(arr, 0, n-1);

    return 0;
}

// TC: O(n*log n)
// SC: O(n)