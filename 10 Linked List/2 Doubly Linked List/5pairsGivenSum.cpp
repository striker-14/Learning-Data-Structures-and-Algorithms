#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

vector<pair<int, int>> pairsGivenSum(Node* head, int target) {

    vector<pair<int, int>> res;

    Node* first = head;
    Node* second = head;

    // move second pointer to the last node
    while (second->next != nullptr) {
        second = second->next;
    }

    // to track if we find a pair or not
    bool found = false;

    while (first != second && second->next != first) {

        if ((first->data + second->data) == target) {

            found = true;
            res.push_back({first->data, second->data});

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            second = second->prev;
        
        } else {
            if ((first->data + second->data) < target) {
                first = first->next;
            } else {
                second = second->next;
            }
        }
    }

    return res;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    int target = 7;

    vector<pair<int, int>> result = pairsGivenSum(head, target);

    if (result.empty()) {
        cout << "No pairs found";
    } else {
        for (auto &num : result) {
            cout << num.first << " " << num.second;
            cout << endl;
        }
    }

    return 0;
}

// TC: O(n)
// SC: O(1) // where k is the number of pairs found