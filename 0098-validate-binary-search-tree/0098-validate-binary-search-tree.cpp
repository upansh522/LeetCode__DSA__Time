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
void inorder_Traversal(TreeNode* root,vector<int> &inorder,bool &ans)
{
    if (root==nullptr)
    return;

    inorder_Traversal(root->left,inorder,ans);
    inorder.push_back(root->val);
    if (inorder.size()>1 && inorder[inorder.size()-2]>=inorder[inorder.size()-1])
    ans=false;
    inorder_Traversal(root->right,inorder,ans);
}
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        bool ans=true;
        inorder_Traversal(root,inorder,ans);
        return ans;
    }
};