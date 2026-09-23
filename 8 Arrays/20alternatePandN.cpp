#include <bits/stdc++.h>
using namespace std;

vector<int> alternatePandN(vector<int> &arr) {

    int n = arr.size();

    vector<int> ans(n,0); // vector to store the answer (n is the size and initialize all elements to zero)

    int posIndex = 0; // must start from positive element
    int negIndex = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2; // because the next negative element will be at at this
        }
        else { // if greater or equal to zero
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }

    return ans;
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, -4, -5};

    vector<int> result = alternatePandN(arr);

    printArray(arr);

    return 0;
}

// TC: O(n(
// SC: O(n)