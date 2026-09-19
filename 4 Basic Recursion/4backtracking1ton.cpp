#include <bits/stdc++.h>
using namespace std;

void printBacktracking(int n) {
    if (n > 0) {
        printBacktracking(n-1);
        cout << n << endl;
    } else {
        return;
    }
}

int main() {
    int n = 10;
    printBacktracking(n);

    return 0;
}