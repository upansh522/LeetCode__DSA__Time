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
void Inorder_Traversal(TreeNode* root,vector<int> &inorder,int key)
{
    if (root==nullptr)
    return;

    Inorder_Traversal(root->left,inorder,key);
    if (root->val!=key)
    inorder.push_back(root->val);
    Inorder_Traversal(root->right,inorder,key);
    return;
}
void balanceTree(TreeNode* &ans,int low,int high,vector<int> &inorder)
{
    if (high<low)
    {
        return;
    }
    int mid=(low+high)/2;
    ans=new TreeNode(inorder[mid]);

    balanceTree(ans->left,low,mid-1,inorder);
    balanceTree(ans->right,mid+1,high,inorder);
    return;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> inorder;

        Inorder_Traversal(root,inorder,key);
        int n=inorder.size();
        int low=0,high=n-1;
        TreeNode* ans;
        balanceTree(ans,low,high,inorder);

        return ans;

    }
};