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
void insert(TreeNode* &currNode,int val,TreeNode* add)
{
    if (currNode->val<val)
    {
        if (currNode->right!=nullptr)
        insert(currNode->right,val,add);
        else
        {
        currNode->right=add;
        return; }
    }

    if (currNode->val>val)
    {
        if (currNode->left!=nullptr)
        insert(currNode->left,val,add);
        else{
        currNode->left=add;
        return; }
    }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* add= new TreeNode(val);

         if (root==nullptr)
         return add;

         insert(root,val,add);
         return root;
    }
};