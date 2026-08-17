#include <bits/stdc++.h>
using namespace std;

void generateBinaryStrings(int n, string curr, vector<string> &result) {

    vector<int> res;

    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // always add 0
    generateBinaryStrings(n, curr + '0', result);
    
    // add 1 only if the previous character is not 1
    if (curr.empty() || curr.back() != '1') {
        generateBinaryStrings(n, curr + '1', result);
    }
}

int main() {
    int n = 3;

    // vector to store result
    vector<string> result; // of string type

    // start recursion with empty string
    generateBinaryStrings(n, " ", result);

    for (string s : result) {
        cout << s << " ";
    }

    return 0;
}

// TC: O(n^2)
// SC: O(n)