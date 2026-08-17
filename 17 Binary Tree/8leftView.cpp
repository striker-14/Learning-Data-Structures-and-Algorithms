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

void recLeftView(Node* root, int level, vector<int> &result) {

    if (root == nullptr) {
        return;
    }

    // first node of current level
    if (level == result.size()) {
        result.push_back(root->data);
    }

    recLeftView(root->left, level + 1, result);
    recLeftView(root->right, level + 1, result);
}

vector<int> leftView(Node* root) {
    vector<int> result;

    recLeftView(root, 0, result);

    return result;
}

int main() {
    //    1
    //   / \
    //  2   3
    //     /
    //    4
    //     \
    //      5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);

    vector<int> result = leftView(root);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(h)