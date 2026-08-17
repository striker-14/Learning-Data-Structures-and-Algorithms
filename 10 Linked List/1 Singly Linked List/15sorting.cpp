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

// Function to split the list into two halves
Node* split(Node* head) {

    Node* fastptr = head;
    Node* slowptr = head;

    while (fastptr != nullptr && fastptr->next != nullptr) {

        fastptr = fastptr->next->next;

        if (fastptr != nullptr) {      
            slowptr = slowptr->next;
        }
    }

    // split the list into two halves
    Node* temp = slowptr->next;
    slowptr->next = nullptr; // for first half
    return temp;
}

// Function to merge two sorted singly linked lists
Node* merge(Node* first, Node* second) {

    // if either list is empty, return the other list
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    // pick the smaller value between first and second nodes
    if (first->data < second->data) {

        // recursively merge the rest of the lists and link the result to the current node
        first->next = merge(first->next, second);

        return first;
    } else {
        // recursively merve the rest of the lists and link the result to the current node
        second->next = merge(first, second->next);

        return second;
    }
}

// Function to perform merge sort on a singly linked list
Node* mergeSort(Node* head) {

    // base case: if the list is empty or has only one node, it's already sorted
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // split the list into two halves
    Node* second = split(head);

    // recursively sort each half
    head = mergeSort(head);
    second = mergeSort(second);

    // merge the two sorted halves
    return merge(head, second);
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);

    head = mergeSort(head);

    printList(head);

    return 0;
}

// TC: O(n*log n)
// SC: O(log n)