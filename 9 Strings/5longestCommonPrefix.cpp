#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr) {

    // sort the array
    sort(arr.begin(), arr.end());

    string first = arr.front();
    string last = arr.back();
    int minLength = min(first.size(), last.size());

    int i = 0;
    
    while (i < minLength && first[i] == last[i]) {
        i++;
    }

    // return the common prefix
    return first.substr(0, i); // not i+1 because we are incrementing i after confirming element
}

int main() {
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};

    cout << longestCommonPrefix(arr);

    return 0;
}

// TC: O(n*m*log n)
// SC: O(m) // for storing first and last element (where m is maximum length of string)