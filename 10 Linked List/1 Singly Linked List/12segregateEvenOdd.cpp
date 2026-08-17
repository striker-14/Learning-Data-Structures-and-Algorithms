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

Node* segregateEvenOdd(Node* head) {

    // result list to hold even nodes
    Node* resStart = nullptr;
    Node* resEnd = nullptr;

    // pointers for the original list
    Node* curr = head;
    Node* prev = nullptr;

    // move all even nodes from original to result
    while (curr != nullptr) {

        // if current node is even
        if (curr->data % 2 == 0) {

            // remove the current even node from the original list
            if (prev != nullptr) {
                prev->next = curr->next;        
            } else {           
                // if the even node is at head          
                head = curr->next;
            }
       
            // add the current even node to the result list       
            if (resStart == nullptr) {
            
                resStart = curr;           
                resEnd = resStart;              
            } else {          
                resEnd->next = curr;         
                resEnd = resEnd->next;
            }
      
            curr = curr->next;
        }
  
        // if the node is odd, just move to the next   
        else {       
            prev = curr;       
            curr = curr->next;
        }
    }

    // if there are no even nodes, return the original list
    if (resStart == nullptr) {
        return head;
    }

    // append the remaining original list (odd nodes) to the result list
    resEnd->next = head;

    // return the result list (starting with even nodes)
    return resStart;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(11);

    head = segregateEvenOdd(head);

    printList(head);

    return 0;
}

// TC: O(n)
// SC: O(1)