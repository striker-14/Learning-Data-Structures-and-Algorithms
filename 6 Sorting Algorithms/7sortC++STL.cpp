#include <bits/stdc++.h>
using namespace std;

// Ascending Order

// For Vector
/* int main() {
    vector<int> arr = {5, 3, 2, 1, 4};

    sort(arr.begin(), arr.end()); // here end() points right after the end element (we have to give range, doesn't include last element that's why we use end())

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
} */

// For Array
/* int main() {
    int arr[] = {5, 3, 2, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + n); // arr points to first element (arr represents the address of first element) and arr + n points right after end element

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
} */


// Descending Order

// Custom comparator for descending order
bool comp(int a, int b) {
    return a > b; // put a before b if a is greater than b (retun a < b (ascending order) -> put a before b if a is smaller than b)
}

int main() {
    int arr[] = {5, 3, 2, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr, arr + n, comp);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}