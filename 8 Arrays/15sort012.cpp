#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr) {

    int low = 0;
    int mid = 0; // we will use mid as iterator to traverse the whole array
    int high = arr.size()-1;

    while (mid <= high) { // we have to cover and compare every element that's why <=

        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        } 
        else {
            swap(arr[mid], arr[high]);
            high--; // didn't increment mid here because the element that gets swapped can be any number and needs to be checked again
        }
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};

    sort012(arr);

    printArray(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)