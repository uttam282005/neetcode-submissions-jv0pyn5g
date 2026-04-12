/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int f(TreeNode *node, int &ans) {
    if (!node) return 0;

    int leftMax = f(node->left, ans);
    int rightMax = f(node->right, ans);

    ans = max({ ans, rightMax + leftMax + node->val, node->val, node->val + rightMax, node->val + leftMax });

    return max( { node->val, node->val + leftMax, node->val + rightMax });
}

// void h(TreeNode* root, int &ans) {
//     if (!root) return;

//     int rootPathSum = f(root);
//     ans = max(ans ,rootPathSum);

//     h(root->left, ans);
//     h(root->right, ans);
// }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN / 2;

        f(root, ans);
        return ans;
    }
};
