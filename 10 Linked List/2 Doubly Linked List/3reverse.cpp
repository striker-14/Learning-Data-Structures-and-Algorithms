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

Node* reverse(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* prevNode = nullptr;
    Node* currNode = head;

    while (currNode != nullptr) {

        // swap the next and prev pointers
        prevNode = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = prevNode;

        // move to the next node in the original list (which is now previous due to reversal)
        currNode = currNode->prev;
    }

    return prevNode->prev;
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

    head = reverse(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)