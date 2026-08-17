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

Node* deleteAllOccurrences(Node* head, int k) {

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == k) {

            if (temp == head) {
                head = head->next;
            }

            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            if (prevNode != nullptr) prevNode->next = nextNode;
            if (nextNode != nullptr) nextNode->prev = prevNode;

            free(temp);
            temp = nextNode;

        } else {
            temp = temp->next;
        }
    }

    return head;
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
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    int k = 2;

    head = deleteAllOccurrences(head, k);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)