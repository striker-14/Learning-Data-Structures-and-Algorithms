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

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node* curr = head;
    Node* newHead = nullptr;
    Node* tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;

        int count = 0;

        // reverese the nodes in the current group
        while (curr != nullptr && count < k) {

            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // if newHead is null, set it to the last node of the first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // connect the previous group to the current reversed group
        if (tail != nullptr) {
            tail->next = prev;
        }

        // move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseKGroup(head, 3);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)