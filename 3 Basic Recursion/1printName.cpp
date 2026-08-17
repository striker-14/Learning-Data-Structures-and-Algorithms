#include <bits/stdc++.h>
using namespace std;

void printName(int n) {
    if (n < 5) {
        cout << "Pranay\n";
        n++;
        printName(n);
    } else {
        return;
    }
}

int main() {
    int n = 0;
    printName(n);

    return 0;
}