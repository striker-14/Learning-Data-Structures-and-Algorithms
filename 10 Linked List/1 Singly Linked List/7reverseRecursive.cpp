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

    if (head == NULL || head->next == NULL) {
        return head;
    }

    // reverse the rest of the LL except the first Node
    Node* rest = reverseList(head->next);

    // make the current head as the last node of remaining linked list
    head->next->next = head;

    head->next = NULL;

    // return the reversed list
    return rest;
}

void printList(Node* curr) {
    while(curr != nullptr) {
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
// SC: O(n)