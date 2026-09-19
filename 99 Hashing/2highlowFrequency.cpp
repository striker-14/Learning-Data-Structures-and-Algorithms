#include <bits/stdc++.h>
using namespace std;

void highlowFrequency(int arr[], int n) {

    unordered_map<int, int> um;

    for (int i = 0; i < n; i++) {
        um[arr[i]]++;
    }

    int highestFreq = 0, highestFreqEle;
    int lowestFreq = n, lowestFreqEle; // we set the value of lowestFreq = n (highest value)

    for (auto num : um) { // (Iterating the unordered_map)

        int element = num.first;
        int count = num.second;

        // For Highest Frequency Element
        if (count > highestFreq) {
            highestFreqEle = element;
            highestFreq = count;
        }

        // For Lowest Frequency Element
        if (count < lowestFreq) {
            lowestFreqEle = element;
            lowestFreq = count;
        }
    }

    cout << "Highest Frequency Element is " << highestFreqEle << " with frequncy of " << highestFreq << endl;
    cout << "Lowest Frequency Element is " << lowestFreqEle << " with frequency of " << lowestFreq;
}

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    highlowFrequency(arr, n);

    return 0;
}

// TC: O(n)
// SC: O(n) // Space complexity of unordered_map is O(n)