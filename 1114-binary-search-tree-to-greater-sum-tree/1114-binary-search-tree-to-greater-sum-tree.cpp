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
    // Helper function to convert BST to GST
    void GreaterTree(TreeNode* node, int &accSum) {
        if (!node) return;
        GreaterTree(node->right, accSum);
        accSum += node->val;
        node->val = accSum;
        GreaterTree(node->left, accSum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int accSum = 0; // Initialize the accumulated sum to 0
        GreaterTree(root, accSum);
        return root;
    }
};
