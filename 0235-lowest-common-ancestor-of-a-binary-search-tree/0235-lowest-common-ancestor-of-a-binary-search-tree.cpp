/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void LCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if (!root) return;
        
        if (root->val == p->val || root->val == q->val) {
            ans = root;
            return;
        }
        
        if ((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val)) {
            ans = root;
            return;
        }

        if (p->val < root->val) {
            LCA(root->left, p, q, ans);
        } else {
            LCA(root->right, p, q, ans);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        LCA(root, p, q, ans);
        return ans;
    }
};
