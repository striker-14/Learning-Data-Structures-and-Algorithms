#include <bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n) {

    vector<int> ans; // to store the divisors

    for (int i = 1; i <= sqrt(n); i++) { // start loop from 1 because divisors start from 1, will run it till including sqrt value
        if (n % i == 0) {

            if (i == sqrt(n)) { // if i is equal to sqrt(n), then we will only include 1 divisor as they both are same
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }

    return ans;
}

int main() {
    int n = 100;
    vector<int> divisors = printDivisors(n);
    for (int num : divisors) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(sqrt(n))
// SC: O(sqrt(n))