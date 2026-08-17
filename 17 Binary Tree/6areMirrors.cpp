#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 

    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

bool areMirrors(Node *r1, Node *r2) {

    // if both roots are empty, they are mirrors
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }

    // if only one root is empty, they are not mirrors
    if (r1 == nullptr || r2 == nullptr) {
        return false;
    }

    return (r1->data == r2->data) && 
        areMirrors(r1->left, r2->right) && 
        areMirrors(r1->right, r2->left);
}

int main() {
    //        1
    //       / \
    //      3   2
    //          / \
    //         5   4
    Node* r1 = new Node(1);
    r1->left = new Node(3);
    r1->right = new Node(2);
    r1->right->left = new Node(5);
    r1->right->right = new Node(4);

    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    r2->left->left = new Node(4);
    r2->left->right = new Node(5);

    cout << (areMirrors(r1, r2) ? "true" : "false");

    return 0;
}

// TC: O(n)
// SC: O(h)