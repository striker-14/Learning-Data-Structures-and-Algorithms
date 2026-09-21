/*
Q5. Print from n to 1 (Using Backtracking).
*/

#include <bits/stdc++.h>
using namespace std;

void printBacktracking(int k, int n) {
    if (k <= n) {
        printBacktracking(k+1, n);
        cout << k << endl;
    } else {
        return;
    }
}

int main() {
    int k = 1;
    int n = 10;
    printBacktracking(k, n);

    return 0;
}