/*
Q7. Print all Divisors. (Factors)
Divisor: is a number that divides n without leaving a remainder.

Input: n = 36
Output: 1, 2, 3, 4, 6, 9, 12, 18, 36

All divisors of a number appear in pairs.
If n = 100, the divisor pairs are:
(1, 100), (2, 50), (4, 25), (5, 20), (10, 10) # After this, they start repeating

# We need to be careful in cases like (10, 10) which happens when n is a perfect square. We should include that divisor only once.

Instead of iterating from 1 to n, we only need to iterate from 1 to √n.
Because for any factor a of n, the corresponding factor b = n/a forms a pair (a, b)
*/

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

// TC: O(√n)
// SC: O(√n)