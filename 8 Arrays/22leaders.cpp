#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr) {

    vector<int> ans; // to store the leaders
    
    int n = arr.size();

    int max = arr[n-1]; // last element of an array is a leader
    ans.push_back(arr[n-1]); // so push it into ans

    for (int i = n-2; i >= 0; i--) { // start traversing from the second last to first
        if (arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i]; // update max
        }
    }

    return ans; // will print in reverse order of their occurences
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> result = leaders(arr);

    printArray(result);

    return 0;
}

// TC: O(n)
// SC: O(n)