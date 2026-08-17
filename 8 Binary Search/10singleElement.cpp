#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr) {

    int low = 0, high = arr.size()-1;

    while (low < high) { // # not equal to because when it is equal, that is the element we are searching for
        int mid = low + (high-low)/2;

        if (mid % 2 == 1) {
            mid--;
        }

        if (arr[mid] == arr[mid+1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }

    return arr[low];
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};

    cout << singleElement(arr);

    return 0;
}

// TC: O(log n)
// SC: O(1)