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

Node* deleteAtEnd(Node* head) {

    // Corner cases
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // traverse to the lasy node
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->prev->next = nullptr;

    delete curr;

    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = deleteAtEnd(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)