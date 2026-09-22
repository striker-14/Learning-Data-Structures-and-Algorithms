#include <bits/stdc++.h>
using namespace std;

// function to find the count of subarrays with sum at most k
int atMostK(vector<int> &arr, int k) {

    if (k < 0) {
        return 0;
    }

    int n = arr.size();

    int res = 0;
    int sum = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {

        while (j < n && sum + arr[j] <= k) {
            sum += arr[j];
            j++;
        }

        // number of subarrays starting from index i that have sum atmost k will be (j-i)
        res += (j-i);

        // remove the ith index from window
        sum -= arr[i];
    }

    return res;
}

// function to find count of subarrays with sum equal to k
int numberOfSubarrays(vector<int> &arr, int k) {

    return atMostK(arr, k) - atMostK(arr, k-1);
}

int main() {
    vector<int> arr = {1, 0, 1, 1, 0, 1};

    int k = 2;

    cout << numberOfSubarrays(arr, k);

    return 0;
}