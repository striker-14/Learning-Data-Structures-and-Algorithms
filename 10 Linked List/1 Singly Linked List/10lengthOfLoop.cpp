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

int countNodes(Node* node) {

    int res = 1;

    Node* curr = node;
    while (curr->next != node) {
        res++;
        curr = curr->next;
    }

    return res;
}

int lengthOfLoop(Node* head) {

    Node *slowptr = head, *fastptr = head;

    while (slowptr != nullptr && fastptr != nullptr && fastptr->next != nullptr) {

        slowptr = slowptr->next;

        fastptr = fastptr->next->next;

        if (slowptr == fastptr) {
            return countNodes(slowptr); // we pass here slowptr not head
        }
    }

    return 0;
}

int main() {
    Node* head = new Node(25);
    head->next = new Node(14);
    head->next->next = new Node(19);
    head->next->next->next = new Node(33);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head->next->next;

    cout << lengthOfLoop(head);

    return 0;
}

// TC: O(n)
// SC: O(1)