// C++ solution.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// recursive implementation
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || root->left == nullptr) { return root; }
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        if (root->left) { connect(root->left); }
        if (root->right) { connect(root->right); }
        return root;
    }
};

// iterative implementation
class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while (cur) {
            Node* t = cur;
            while (t) {
                if (t->left) { t->left->next = t->right; }
                if (t->right && t->next) { t->right->next = t->next->left; }
                t = t->next;
            }
            cur = cur->left;
        }
        return root;
    }
};