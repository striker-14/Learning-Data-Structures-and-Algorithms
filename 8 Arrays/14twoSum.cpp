#include <bits/stdc++.h>
using namespace std;

string twoSum(vector<int> &arr, int target) {

    sort(arr.begin(), arr.end()); // first sort the array

    int left = 0, right = arr.size()-1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return "YES";
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--; // decrement the right pointer if sum > target
        }
    }

    return "NO";
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    cout << twoSum(arr, target);

    return 0;
}

// TC: O(n)
// SC: O(1)