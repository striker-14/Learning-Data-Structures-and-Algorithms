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

int maxPathSumRec(Node *root, int &res) {

    if (root == nullptr) {
        return 0;
    }

    // calculate maximum path sums for left and right subtrees
    int l = max(0, maxPathSumRec(root->left, res));
    int r = max(0, maxPathSumRec(root->right, res));

    // update 'res' with the maximum path sum passing through the current node
    res = max(res, l + r + root->data);

    return root->data + max(l, r);
}

int maxPathSum(Node* root) {

    int res = root->data;

    // compute max path sum and store it in res
    maxPathSumRec(root, res);

    return res;
}

int main() {
    //            10
    //           /  \
    //          2    10
    //         / \     \  
    //        20  1    -25
  	//                 /  \
  	//				  3	   4
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << maxPathSum(root);
}

// TC: O(n) // If there are n nodes in the tree, it makes exactly n function calls.
// SC: O(h) // where h is the height of the tree, due to the recursive call stack
// The deepest the recursion goes at any one time is from the root down to the deepest leaf node. The number of active calls on the stack at this point is equal to the height of the tree, $h$.