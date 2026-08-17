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

int isBalancedRec(Node *root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = isBalancedRec(root->left);
    int rightHeight = isBalancedRec(root->right);

    // If either the subtrees are unbalanced or the absolute difference difference of their heights is greater than 1, return -1
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root) {
    return (isBalancedRec(root) > 0);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout << (isBalanced(root) ? "true" : "false");

    return 0;
}

// TC: O(n)
// SC: O(n)