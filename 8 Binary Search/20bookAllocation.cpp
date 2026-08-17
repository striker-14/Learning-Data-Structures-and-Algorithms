#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int k, int pageLimit) {

    int count = 1; // for first student
    int pageSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pageSum + arr[i] > pageLimit) {
            count++;
            pageSum = arr[i];
        } else {
            pageSum += arr[i];
        }
    }

    // if books can be assigned to less than k students then it can be assigned to exactly k students as well
    return (count <= k);
}

int bookAllocation(vector<int> &arr, int k) {

    // if number of students are more than total books then allocation is  not possible
    if (k > arr.size()) {
        return -1;
    }

    // search space for binary search
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int res = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (check(arr, k, mid)) {
            res = mid;
            high = mid - 1; // low number of pages is possible
        } else {
            low = mid + 1;
        }
    }
    
    return res;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};

    int k = 2;

    cout << bookAllocation(arr, k);

    return 0;
}

// TC: O(n*log(sum(arr)-max(arr))
// SC: O(1)