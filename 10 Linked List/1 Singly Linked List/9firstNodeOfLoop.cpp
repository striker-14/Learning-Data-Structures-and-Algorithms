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

int firstNodeOfLoop(Node* head) {

    Node *slowptr = head, *fastptr = head;

    while (fastptr != nullptr && fastptr->next != nullptr) {

        slowptr = slowptr->next;

        fastptr = fastptr->next->next;

        if (slowptr == fastptr) {

            slowptr = head;

            while (slowptr != fastptr) {
                slowptr = slowptr->next;
                fastptr = fastptr->next;     
            }
       
            // return the meeting point which is the start of the loop        
            return slowptr->data;
        }
    }

    return -1;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    head->next->next->next->next->next->next = head->next->next;

    cout << firstNodeOfLoop(head);

    return 0;
}

// TC: O(n)
// SC: O(1)