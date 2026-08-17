#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int x, int n) {

    int low = 0, high = n-1;

    int res = -1;

    while (low <= high) {

        int mid = low + (high-low)/2;

        if (arr[mid] <= x) { // maybe an answer
            res = arr[mid]; // # return element not index
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return res;
}

int findCeil(vector<int> &arr, int x, int n) {

    int low = 0, high = n-1;

    int res = 0;

    while (low <= high) {

        int mid = low + (high-low)/2;

        if (arr[mid] >= x) {
            res = arr[mid]; // # return element not index
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

pair<int, int> getFloorAndCeil(vector<int> &arr, int x, int n) {
    int f = findFloor(arr, x, n);
    int c = findCeil(arr, x, n);
    return make_pair(f, c);
}

int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int n = arr.size();

    int x = 5;

    pair<int, int> result = getFloorAndCeil(arr, x, n);

    cout << "Floor: " << result.first << endl << "Ceil: " << result.second;

    return 0;
}

// TC: O(log n)
// SC: O(1)