#include <bits/stdc++.h>
using namespace std;

int leastWeightCapacity(vector<int> &weight, int d) {

    int n = weight.size();

    int left = -1, right = 0;

    for (int i = 0; i < n; i++) {
        right += weight[i]; // sum of all weights
        left = max(left, weight[i]); // max weight among them
    }

    while (left < right) { // not equal
        int mid = left + (right-left)/2;
        int need = 1; // days (we need atleast 1 day to ship the packages)
        int curr = 0; // current weight

        for (int i = 0; i < n && need <= d;) { // didn't increment here, introduced condition for days
            // # notice that we had to add ; after d because we are running loop and verifying condition together
            curr += weight[i];
            i++;
            if (curr + weight[i] > mid) { // checking it after incrementing i
                curr = 0; // set current weight to 0
                need++; // increase day by 1 (for next package)
            }
        }

        // if number of days needed exceeds the given limit, we need to increase the weight capacity and update left
        if (need > d) {
            left = mid + 1;
        } else { // if within limit, reduce the weight capacity
            right = mid;
        }
    }

    return left;

}

int main() {
    vector<int> weight = {1, 2, 3, 4, 5, 6, 7};

    int d = 5;

    cout << leastWeightCapacity(weight, d);

    return 0;
}

// TC: O(n*log(sum))
// SC: O(1)