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

Node* removeDuplicates(Node* head) {

    Node* temp = head;
    while (temp != nullptr and temp->next != nullptr) {

        Node* nextNode = temp->next;
        while (nextNode != nullptr && nextNode->data == temp->data) {

            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if (nextNode != nullptr) nextNode->prev = temp;

        temp = temp->next;
    }

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
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;

    head = removeDuplicates(head);

    printList(head);

    return 0;
}

// TC: O(n) // because we are traversing all the nodes (once)
// SC: O(1)