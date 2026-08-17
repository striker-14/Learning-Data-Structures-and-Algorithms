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

void serializePreOrder(Node *root, vector<int> &arr) {

    if (root == nullptr) {
        arr.push_back(-1);
        return;
    }

    // push the root into result
    arr.push_back(root->data);
    serializePreOrder(root->left, arr);
    serializePreOrder(root->right, arr);
}

vector<int> serialize(Node *root) {
    vector<int> arr;

    serializePreOrder(root, arr);

    return arr;
}

Node* deserializePreOrder(int &i, vector<int> &arr) {

    // if element is -1, return null
    if (arr[i] == -1) {
        i++;
        return nullptr;
    }

    // create the root node
    Node* root = new Node(arr[i]);
    i++;

    // create the left and right subtree
    root->left = deserializePreOrder(i, arr);
    root->right = deserializePreOrder(i, arr);

    return root;
}

Node* deserialize(vector<int> &arr) {
    int i = 0;
    return deserializePreOrder(i, arr);
}

int main() {
    //       10
    //     /    \
    //    20    30
    //  /   \
    // 40  60
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    vector<int> result = serialize(root);
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC: O(n)
// SC: O(n)