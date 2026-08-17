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

void recRightView(Node *root, int level, vector<int> &res) {

    if (root == nullptr) {
        return;
    }

    // first node of current level
    if (level == res.size()) {
        res.push_back(root->data);
    }

    recRightView(root->right, level + 1, res);
    recRightView(root->left, level + 1, res);
}

vector<int> rightView(Node *root) {
    vector<int> res;

    recRightView(root, 0, res);

    return res;
}

int main() {
    //         1
    //        / \
    //       2   3
    //           / \   
    //          4   5  
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(h)