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

int middleNode(Node* head) {

    Node* slowptr = head;
    Node* fastptr = head;

    while (fastptr != NULL && fastptr->next != NULL) {

        fastptr = fastptr->next->next;

        slowptr = slowptr->next;
    }

    return slowptr->data;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);    
    head->next->next = new Node(30);    
    head->next->next->next = new Node(40);    
    head->next->next->next->next = new Node(50);    
    head->next->next->next->next->next = new Node(60);
    
    cout << middleNode(head);

    return 0;
}

// TC: O(n)
// SC: O(1)