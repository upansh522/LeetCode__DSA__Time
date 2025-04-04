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
    int dfs(TreeNode* node,int depth,pair<int,TreeNode*>& ans){
        if (!node){
            return depth;
        }

        int left,right;        
        left=dfs(node->left, depth+1,ans);      
        right=dfs(node->right, depth+1,ans);
        


        if (left==right && left>=ans.first){
            ans={left,node};
        }

        return max(left,right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int,TreeNode*> ans={0,nullptr};
        int depth=dfs(root,0,ans);

        return ans.second;        
    }
};