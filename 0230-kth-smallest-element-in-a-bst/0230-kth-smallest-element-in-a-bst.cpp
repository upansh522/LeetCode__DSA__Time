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
    void solve(TreeNode* root,int k,int &pos,int &val){
        if(root==NULL)
            return;
        solve(root->left,k,pos,val);
        pos++;
        if(pos==k){
            val=root->val;
            return;
        }
        solve(root->right,k,pos,val);
    }
    int kthSmallest(TreeNode* root, int k) {
        int val=0,pos=0;
        solve(root,k,pos,val);
        return val;
    }
};