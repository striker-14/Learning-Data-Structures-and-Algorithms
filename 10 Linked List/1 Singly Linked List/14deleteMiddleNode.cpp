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

Node* deleteMiddleNode(Node* head) {

    // if the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // if the list contains only one node, delete it and return NULL
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* prev = NULL;

    Node* slowptr = head;
    Node* fastptr = head;

    while (fastptr != NULL && fastptr->next != NULL) {

        fastptr = fastptr->next->next;

        // update prev to  hold the previous slowptr value
        prev = slowptr;

        slowptr = slowptr->next;
    }

    // bypass the middle node
    prev->next = slowptr->next;

    // delete the middle node
    delete slowptr;

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

    head = deleteMiddleNode(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)