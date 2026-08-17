#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {

    int cnt = 0; // Initialized the count to store how many times the loop is running which gives the number of digits

    while (n > 0) {

        cnt++;

        n = n / 10;
    }
    return cnt;
}

int main() {
    int n = 7789;
    int count = countDigits(n);
    cout << count;

    return 0;
}