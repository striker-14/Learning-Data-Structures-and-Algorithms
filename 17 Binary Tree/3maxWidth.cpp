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

int maxWidth(Node *root) {

    if (root == nullptr) {
        return 0;
    }

    int result = 0;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {

        int count = q.size();

        result = max(count, result);

        while(count) {
            
            Node* temp = q.front();
            q.pop();

            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }

            count--;
        }
    }

    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    cout << maxWidth(root);

    return 0;
}

// TC: O(n)
// SC: O(n)