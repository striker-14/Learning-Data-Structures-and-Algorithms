#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in a Singly Linked List
struct Node {

    int data;

    Node* next;

    // Constructor to initialize the node with data
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to insert a new node the at the beginning of the list
Node* insertAtHead(Node* head, int data) {

    // create a new node with the given data
    Node* new_node = new Node(data);

    // make the next of the new node point to the current head
    new_node->next = head;

    // return the new node as the new head of the list
    return new_node;
}

// Function to print the contents of the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    int data = 1;

    head = insertAtHead(head, data);

    printList(head);

    return 0;
}

// TC: O(1)
// SC: O(1)