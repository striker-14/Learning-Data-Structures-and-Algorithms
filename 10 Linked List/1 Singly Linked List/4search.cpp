#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

bool searchKey(Node* head, int key) {

    Node* curr = head;

    while (curr != nullptr) {

        if (curr->data = key) {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

int main() {
    Node* head = new Node(14);
    head->next = new Node(21);
    head->next->next = new Node(13);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(10);

    int key = 14;

    cout << searchKey(head, key);

    return 0;
}

// TC: O(n)
// SC: O(1)