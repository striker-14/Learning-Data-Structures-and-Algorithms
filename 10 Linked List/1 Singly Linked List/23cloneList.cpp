#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *random;
    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};

Node* cloneList(Node* head) {

    if (head == NULL) {
        return NULL;
    }

    // create new nodes and insert them next to the original nodes
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // set the random pointers of the new nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // separate the new nodes from the original nodes
    curr = head;
    Node* clonedHead = head->next;
    Node* clone = clonedHead;
    while (clone->next != NULL) {

        // update the next nodes of original node nd cloned node
        curr->next = curr->next->next;
        clone->next = clone->next->next;

        // move pointers of original as well as cloned linked list ot their next nodes
        curr = curr->next;
        clone = clone->next;
    }

    curr->next = NULL;
    clone->next = NULL;

    return clonedHead;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
        if (head->random) {
            cout << head->random->data << ")";
        } else {
            cout << "null" << ")";
        }

        if (head->next != NULL) {
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    Node* clone = cloneList(head);

    printList(clone);

    return 0;
}

// TC: O(n)
// SC: O(1)