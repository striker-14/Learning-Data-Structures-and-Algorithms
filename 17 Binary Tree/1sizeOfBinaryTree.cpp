#include <bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *left, *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Function to find the size of the binary tree
int getSize(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    // Find the size of the left subtree and right subtree
    int left = getSize(root->left);
    int right = getSize(root->right);

    return left + right + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << getSize(root);

    return 0;
}

// TC: O(n)
// SC: O(n)