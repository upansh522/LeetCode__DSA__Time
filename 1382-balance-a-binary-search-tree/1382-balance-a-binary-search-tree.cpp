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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;

        Inorder_Traversal(root,inorder);
        int n=inorder.size();
        int low=0,high=n-1;
        TreeNode* ans;
        balanceTree(ans,low,high,inorder);

        return ans;
    }
};