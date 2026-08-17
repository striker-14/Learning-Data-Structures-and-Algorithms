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

Node* reverseList(Node* head) {

    // Initialize three pointers
    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr) {

        next = curr->next;

        curr->next = prev;

        prev = curr;
    
        curr = next;
    }

    // return the head of reversed linked list
    return prev;
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

    head = reverseList(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)