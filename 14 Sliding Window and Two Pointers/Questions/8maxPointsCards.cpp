#include <bits/stdc++.h>
using namespace std;

int maxPointsCards(vector<int> &cardPoints, int k) {

    int n = cardPoints.size();

    int total = 0;

    for (int i = 0; i < k; i++) {
        total += cardPoints[i];
    }

    int maxPoints = total;

    for (int i = 0; i < k; i++) {

        // remove card from the front (means the most recent card (right one))
        total -= cardPoints[k-i-1];

        // add card from the back of the array
        total += cardPoints[n-i-1];

        maxPoints = max(maxPoints, total);
    }

    return maxPoints;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};

    int k = 3;

    cout << maxPointsCards(cardPoints, k);

    return 0;
}

// TC: O(k)
// SC: O(1)