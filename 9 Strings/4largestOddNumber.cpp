#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string s) {

    for (int i = s.size()-1; i >= 0; i--) {

        if (s[i] % 2 != 0) { // means it is odd

            string res = s.substr(0, i + 1); // substr() doesn't include last element

            return res;
        }
    }

    // else
    return " ";
}

int main() {
    string s = "54376";

    cout << largestOddNumber(s);

    return 0;
}

// TC: O(n)
// SC: O(1)