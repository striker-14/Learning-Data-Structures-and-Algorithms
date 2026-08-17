#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;;
    }
};

Node* segregate(Node* head) {

    // there's nothing ot segregate/sort, simply return the list as it is
    if (!head || !(head->next)) {
        return head;
    }

    Node* zeroD = new Node(-1); // Dummy
    Node* oneD = new Node(-1);
    Node* twoD = new Node(-1);

    // tails for three lists
    Node* zero = zeroD;
    Node* one = oneD;
    Node* two = twoD;

    // traverse the original list
    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }

        curr = curr->next;
    }

    // connect three lists together
    zero->next = oneD->next; // zero list connects to one list
    one->next = twoD->next; // one list connects to two list
    two->next = nullptr; // end of two list

    // Handle empty cases explicitly
    if (!oneD->next) {
        zero->next = twoD->next;
    }

    if (!oneD->next && !twoD->next) {
        zero->next = nullptr;
    }

    // new head
    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(2);

    head = segregate(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)