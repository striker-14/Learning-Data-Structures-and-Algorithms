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

bool isIdentical(Node *r1, Node *r2) {

    // if both trees are empty, they are identical
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }

    // if only one tree is empty, they are not identical
    if (r1 == nullptr || r2 == nullptr) {
        return false;
    }

    return (r1->data == r2->data) && 
        isIdentical(r1->left, r2->left) && 
        isIdentical(r1->right, r2->right);
}

int main() {
    Node* r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);
    r1->left->left = new Node(4);

    Node* r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    r2->left->left = new Node(4);

    cout << (isIdentical(r1, r2) ? "true" : "false");

    return 0;
}

// TC: O(n)
// SC: O(h)