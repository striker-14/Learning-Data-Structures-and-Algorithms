#include <bits/stdc++.h>
using namespace std;

void printLinearly(int k, int n) {
    if (k <= n) {
        cout << k << endl;
        k++;
        printLinearly(k, n);
    } else {
        return;
    }
}

int main() {
    int k = 1;
    int n = 10;
    printLinearly(k, n);

    return 0;
}