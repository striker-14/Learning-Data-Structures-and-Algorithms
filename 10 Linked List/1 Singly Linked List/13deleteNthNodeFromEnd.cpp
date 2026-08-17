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

Node* deleteNthNodeFromEnd(Node* head, int n) {

    Node* slowptr = head;
    Node* fastptr = head;

    for (int i = 0; i < n; i++) {
        fastptr = fastptr->next;
    }

    // if fasptr becomes null, then head is the nth node from the end
    if (fastptr == nullptr) {
        return head->next; // means skip head
    }

    // move both pointers until fast reaches the end
    while (fastptr->next != nullptr) {
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }

    // remove the nth node form the end
    slowptr->next = slowptr->next->next;
    return head;
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

    int n = 4;

    head = deleteNthNodeFromEnd(head, n);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)