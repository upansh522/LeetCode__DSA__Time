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
void Inorder_Traversal(TreeNode* root,vector<int> &inorder)
{
    if (root==nullptr)
    return;

    Inorder_Traversal(root->left,inorder);
    inorder.push_back(root->val);
    Inorder_Traversal(root->right,inorder);
    return;
}

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;

        Inorder_Traversal(root,inorder);
        int n=inorder.size();

        return inorder[k-1];
    }
};