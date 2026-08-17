#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* deleteHead(Node* head) {

    // check if the list is empty
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;

    head = head->next;

    delete temp;

    return head;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(18);

    head = deleteHead(head);

    printList(head);

    return 0;
}

// TC: O(1) // because the operation to delete head is performed in constant time
// SC: O(1)