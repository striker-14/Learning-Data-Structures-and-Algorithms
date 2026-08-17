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

Node* insertAtEnd(Node* head, int new_data) {

    // create a new node
    Node* new_node = new Node(new_data);

    // if the linked list is empty, set the new node as head of the linked list
    if (head == NULL) {
        return head = new_node;
    }

    Node* curr = head;
    while (curr->next != nullptr) { // here we used curr->next because we want to reach the end node and not make curr as null
        curr = curr->next;
    }

    // set the next of last node to new node
    curr->next = new_node;

    new_node->prev = curr;

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

    int new_data = 4;

    head = insertAtEnd(head, new_data);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)