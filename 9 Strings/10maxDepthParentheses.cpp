#include <bits/stdc++.h>
using namespace std;

int maxDepth(string &s) {

    int current_max = 0; // current count
    int max = 0; // overall maximum count

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            current_max++;

            // update max if required
            if (current_max > max) {
                max = current_max;
            }

        } else if (s[i] == ')') {
            if (current_max > 0) {
                current_max--;
            } else {
                return -1;
            }
        }
    }
        
    // finally check for unbalanced string
    if (current_max != 0) {
        return -1;
    }

    return max;
}

int main() {
    string s = "(((X)) (((Y))))";

    cout << maxDepth(s);

    return 0;
}

// TC: O(n)
// SC: O(1)