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

bool isSumTree(Node *root) {

    if (root == nullptr) {
        return 0;
    }

    // if node is left node, return its value
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    // calculate left subtree sum
    int ls = isSumTree(root->left);

    // if left subtree is not sum tree, return -1
    if (ls == -1) {
        return -1;
    }

    // calculate right subtree sum
    int rs = isSumTree(root->right);

    if (rs == -1) {
        return -1;
    }

    if (ls + rs == root->data) {
        return ls + rs + root->data;
    } else {
        return -1;
    }
}

int main() {
    //       26
    //      /  \
    //     10   3
    //    / \    \
    //   4  6     3
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    cout << (isSumTree(root) ? "true" : "false");

    return 0;
}

// TC: O(n)
// SC: O(h) 