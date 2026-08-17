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

int countNodes(Node *head) {

    int count = 0;

    Node* curr = head;

    while (curr != nullptr) {

        count++;

        curr = curr->next;
    }

    return count;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << countNodes(head);

    return 0;
}

// TC: O(n)
// SC: O(1)