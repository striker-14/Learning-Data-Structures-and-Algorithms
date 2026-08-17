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
    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

// Function ot add one to a linked list and return the head node of the resultant list
Node* addOneUtil(Node* head) {
    
    Node* res = head;
    Node* curr = head;
    Node* last =  nullptr;

    // intialize carry with 1 (to add one)
    int carry = 1;
    int sum;
    
    while (curr != nullptr) {
        // calculate sum of, carry and current node's data
        sum = carry + curr->data;

        // update carry for next digit
        carry = (sum >= 10) ? 1 : 0;

        // update current node's data to sum modulo 10
        curr->data = sum % 10;

        // move to the next node
        last = curr;
        curr = curr->next;
    }

    // if there's a carry left, add a new node with the carry value
    if (carry > 0) {
        last->next = new Node(carry);
    }

    return res;
}

// Main function to add one to the linked list
Node* addOne(Node* head) {

    head = reverseList(head);

    // add one to the reversed list
    head = addOneUtil(head);

    return reverseList(head);
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    head = addOne(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)