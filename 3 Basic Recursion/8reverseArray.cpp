#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int l, int r) {
    if (l >= r) {
        return;
    } else {
        swap(arr[l], arr[r]);
        reverseArray(arr, l+1, r-1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, l, r-1);

    for (int num : arr) {
        cout << num << endl;
    }

    return 0;
}