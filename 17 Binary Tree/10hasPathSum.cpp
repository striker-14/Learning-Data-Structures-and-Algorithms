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

bool hasPathSum(Node *root, int sum) {

    if (root == nullptr) {
        return 0;
    }

    int subSum = sum - root->data;

    // if we reach a leaf node and the sum becomes 0, then return true
    if (subSum == 0 && root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    // otherwise check both subtrees
    bool left = 0, right = 0;

    if (root->left) {
        left = hasPathSum(root->left, subSum);
    }
    if (root->right) {
        right = hasPathSum(root->right, subSum);
    }

    return left || right;
}

int main() {
    //         10
    //       /    \
    //      8      2
    //     / \    /
    //    3   5  2
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    int sum = 21;

    cout << (hasPathSum(root, sum) ? "true" : "false");

    return 0;
}

// TC: O(n)
// SC: O(h)