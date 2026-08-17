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

Node* addTwoLists(Node* head1, Node* head2) {

    head1 = reverseList(head1);
    head2 = reverseList(head2);

    Node* sum = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {

        int newVal = carry;

        if (head1) {
            newVal += head1->data;
            head1 = head1->next;
        }

        if (head2) {
            newVal += head2->data;
            head2 = head2->next;
        }

        carry = newVal / 10; // will be carry like 1, 0
        newVal %= 10;

        // insert the new digit at the front of the result list
        Node* newNode = new Node(newVal);
        newNode->next = sum;
        sum = newNode;
    }

    // remove leading zeros, if any
    while (sum != NULL && sum->data == 0) {
        
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    // if result is empty, return single node with 0
    if (sum == NULL) {
        return new Node(0);
    }

    return sum;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(9);
    head2->next = new Node(9);
    head2->next->next = new Node(9);

    Node* sum = addTwoLists(head1, head2);

    printList(sum);

    return 0;
}

// TC: O(m+n)
// SC: O(1)