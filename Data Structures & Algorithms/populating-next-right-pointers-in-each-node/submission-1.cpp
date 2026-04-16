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

class Solution {
public:
void dfs(Node* root) {
    if (!root) return;

    if (root->left)  {
        root->left->next = root->right;
        dfs(root->left);
    }

    if (root->right) {
        if (!root->next) root->right->next = nullptr;
        else root->right->next = root->next->left;
        dfs(root->right);
    }

}
    Node* connect(Node* root) {
        if (!root) return root;
        root->next = nullptr;
        dfs(root);
        return root;
    }
};