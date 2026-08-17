#include <bits/stdc++.h>
using namespace std;

bool areRotations(string &s, string &goal) {

    // strings must be the same length to be rotations of each other
    if (s.length() != goal.length()) {
        return false;
    }

    // double the string
    string doubleS = s + s;

    return doubleS.find(goal) != string::npos;

    // # string::npos is a special constant meaning "not found". It becomes true when goal is found, and false when it is not
}

int main() {
    string s = "rotation";
    string goal = "tionrota";

    cout << areRotations(s, goal);

    return 0;
}

// TC: O(n)
// SC: O(n)