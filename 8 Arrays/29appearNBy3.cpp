#include <bits/stdc++.h>
using namespace std;

int appearNBy3(vector<int> &arr) {

    int n = arr.size();

    int count1 = 0, count2 = 0;

    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < arr.size(); i++) { // this is a loop to identify first and second

        if (arr[i] == first) {
            count1++;
        }
        else if (arr[i] == second) {
            count2++;
        }
        else if (count1 == 0) { // if count becomes zero change the element
            first = arr[i];
            count1++;
        }
        else if (count2 == 0) {
            second = arr[i];
            count2++;
        }
        else { // if we encounter a completely different element
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    // loop to check how many times they appeared
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == first) {
            count1++;
        }
        else if (arr[i] == second) {
            count2++;
        }
    }

    // check if the count of elements is n/3 or more
    if (count1 > n/3) {
        return first;
    }
        
    if (count2 > n/3) {
        return second;
    }

    // if not then return -1
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1};

    cout << appearNBy3(arr);

    return 0;
}

// TC: O(n)
// SC: O(1)