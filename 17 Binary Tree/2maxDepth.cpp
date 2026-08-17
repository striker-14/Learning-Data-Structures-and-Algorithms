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

int maxDepth(Node *root) {

    if (root == nullptr) {
        return -1; // in size we used 0
    }

    // Compute the height of the left and right subtrees
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    cout << maxDepth(root);

    return 0;
}

// TC: O(n)
// SC: O(n)