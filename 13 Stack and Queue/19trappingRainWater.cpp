#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> height) {

    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < height.size(); i++) {

        int maxLeft = 0;
        int maxRight = 0;

        // find the maximum height to the left of the current bar
        for (int j = 0; j <= i; j++) { // #includes the current element as well
            if (height[j] > maxLeft) {
                maxLeft = height[j];
            }
        }

        // find the maximum height to the right of the current bar
        for (int j = i; j < n; j++) { // #includes the current element as well
            if (height[j] > maxRight) {
                maxRight = height[j];
            }
        }

        // water trapped on current bar is the min of maxLeft and maxRight minus current height
        totalWater += min(maxLeft, maxRight) - height[i];
    }

    return totalWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trappingRainWater(height);

    return 0;
}

// TC: O(n^2)
// SC: O(1)