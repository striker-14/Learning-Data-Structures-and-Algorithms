#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *bottom; // bottom
    Node(int x) {
        data = x;
        next = bottom = nullptr;
    }
};

// Utility function to merge two sorted linked lists using their bottom pointers
Node* merge(Node* head1, Node* head2) {

    // a dummy first node to store the result list
    Node dummy(-1);

    // tail points to the last result node to add new nodes to the result
    Node* tail = &dummy;

    // iterate till either head1 or head2 does not reach NULL
    while (head1 && head2) {

        if (head1->data <= head2->data) {

            // append head 1 to the result
            tail->bottom = head1;
            head1 = head1->bottom;
        } else {
            // append head2 to the result
            tail->bottom = head2;
            head2 = head2->bottom;
        }

        // move tail pointer to the next node
        tail = tail->bottom;
    }

    // append the remaining nodes of the non-null linked list
    if (!head1) {
        tail->bottom = head2;
    } else {
        tail->bottom = head1;
    }

    return (dummy.bottom);
}

// Function to flatten the linked list
Node* flattenList(Node* root) {

    // Base Cases 
    if (root == nullptr || root->next == nullptr) {
        return root;
    }

    // recur for next list
    root->next = flattenList(root->next);

    // now merge the current and next list
    root = merge(root, root->next);

    // return the root
    return root;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->bottom;
    }
}

int main() {
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    head = flattenList(head);

    printList(head);

    return 0;
}

// TC: O(n*n*m)
// SC: O(n)