#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &arr, int n) {

    int largest = arr[0];
    int secLargest = -1; // it is stated that if it doesn't exist return -1

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secLargest = largest; // first we set the value of secLargest because the value of largest is going to change
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > secLargest) {
            secLargest = arr[i];
        }
    }
    return secLargest;
}

int secondSmallest(vector<int> &arr, int n) {

    int smallest = arr[0];
    int secSmallest = INT_MAX; // maximum value an int can store (largest possible integer value)

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            secSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] != smallest && arr[i] < secSmallest) {
            secSmallest = arr[i];
        }
    }
    return secSmallest;
}

int main() {
    vector<int> arr = {4, 3, 1, 2, 5};
    int n = arr.size();

    int sLargest = secondLargest(arr, n);
    int sSmallest = secondSmallest(arr, n);

    cout << "Second Largest: " << sLargest << endl;
    cout << "Second Smallest: " << sSmallest << endl;

    return 0;
}

// TC: O(n)
// SC: O(1)