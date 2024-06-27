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
    void Pre_To_Bst(vector<int>& preorder, TreeNode* &ans, int &ind, stack<TreeNode*>& st) {
        if (ind == preorder.size()) {
            return;
        }
        
        ans = new TreeNode(preorder[ind]);
        ind++;
        
        TreeNode* curr = ans;
        
        while (ind < preorder.size()) {
            if (preorder[ind] < curr->val) {
                curr->left = new TreeNode(preorder[ind]);
                st.push(curr);
                curr = curr->left;
                ind++;
            } else {
                while (!st.empty() && preorder[ind] > st.top()->val) {
                    curr = st.top();
                    st.pop();
                }
                curr->right = new TreeNode(preorder[ind]);
                curr = curr->right;
                ind++;
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* ans = nullptr;
        int ind = 0;
        Pre_To_Bst(preorder, ans, ind, st);

        return ans;
    }
};
