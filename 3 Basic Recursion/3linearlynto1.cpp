#include <bits/stdc++.h>
using namespace std;

void printLinearly(int n) {
    if (n >= 1) {
        cout << n << endl;
        n--;
        printLinearly(n);
    } else {
        return;
    }
}

int main() {
    int n = 10;
    printLinearly(n);

    return 0;
}