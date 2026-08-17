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

void inorderTraversal(Node *root, vector<int> &res) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree first
    inorderTraversal(root->left, res);

    // Visit the current node
    res.push_back(root->data);

    // Traverse the right subtree last
    inorderTraversal(root->right, res);
}

int main() {
    // Create binary tree
    //       1
    //      /  \
    //    2     3
    //   / \     \
    //  4   5     6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> res;
    inorderTraversal(root, res);

    for (int num : res) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(n)