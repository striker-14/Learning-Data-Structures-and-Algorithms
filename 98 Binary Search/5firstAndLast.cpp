#include <bits/stdc++.h>
using namespace std;

int findLast(vector<int> &arr, int x, int n) {

    int low = 0, high = n-1;

    int last = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // because we are finding the last occurrence
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return last;
}

int findFirst(vector<int> &arr, int x, int n) {

    int low = 0, high = n-1;

    int first = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // because we are finding the first
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return first;
}

pair<int, int> findFirstAndLast(vector<int> &arr, int x, int n) {

    int first = findFirst(arr, x, n);

    if (first == -1) {
        return {-1, -1}; // element not found
    }

    int last = findLast(arr, x, n);

    return {first, last}; // new syntax
}

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 6, 7, 123, 125};
    int n = arr.size();

    int x = 5;

    pair<int, int> result = findFirstAndLast(arr, x, n);

    cout << "First: " << result.first << endl << "Last: " << result.second;

    return 0;
}

// TC: O(log n)
// SC: O(1)