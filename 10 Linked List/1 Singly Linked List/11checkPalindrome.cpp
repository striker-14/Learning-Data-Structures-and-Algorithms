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

// Function to reverse a linked list
Node* reverseList(Node* head) {

    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = nullptr;

        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to check if two lists are identical
bool isIdentical(Node* n1, Node* n2) {

    while (n1 != nullptr && n2 != nullptr) {

        if (n1->data != n2->data) {
            return false;
        }

        n1 = n1->next;
        n2 = n2->next;
    }

    return true;
}

bool isPalindrome(Node* head) {

    if (!head || !head->next) {
        return true;
    }

    Node *slowptr = head, *fastptr = head;

    while (fastptr->next && fastptr->next->next) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    // split the list and reverse the second half
    Node* head2 = reverseList(slowptr->next);
    
    slowptr->next = nullptr; // end the first half

    // check if two halves are identical
    bool check = isIdentical(head, head2);

    // restore the original list
    head2 = reverseList(head2);
    slowptr->next = head2;

    return check;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << isPalindrome(head);

    return 0;
}

// TC: O(n)
// SC: O(1)