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
void Inorder_Traversal(TreeNode* root,priority_queue<int> &max_heap,int k)
{
    if (root==nullptr)
    return;

    Inorder_Traversal(root->left,max_heap,k);
    max_heap.push(root->val);
    if (max_heap.size()>k)
    {
        max_heap.pop();
    }
    Inorder_Traversal(root->right,max_heap,k);
    return;
}

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>max_heap;

        Inorder_Traversal(root,max_heap,k);
        return max_heap.top();
        
    }
};