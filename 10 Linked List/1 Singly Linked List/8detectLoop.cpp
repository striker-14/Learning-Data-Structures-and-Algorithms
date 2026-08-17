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

bool detectLoop(Node* head) {

    Node *slowptr = head, *fastptr = head;

    while (slowptr && fastptr && fastptr->next) {

        fastptr = fastptr->next->next;

        slowptr = slowptr->next;

        if (slowptr == fastptr) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    head->next->next->next = head->next;

    cout << detectLoop(head);

    return 0;
}

// TC: O(n)
// SC: O(1)