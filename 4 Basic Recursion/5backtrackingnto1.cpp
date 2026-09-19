#include <bits/stdc++.h>
using namespace std;

void printBacktracking(int k, int n) {
    if (k <= 10) {
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