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
    void lca(TreeNode* currNode, TreeNode* p, TreeNode* q, bool &foundP, bool &foundQ, std::stack<TreeNode*> &stackP, std::stack<TreeNode*> &stackQ) {
        if (currNode == nullptr || (foundP && foundQ)) {
            return;
        }

        if (!foundP) stackP.push(currNode);
        if (!foundQ) stackQ.push(currNode);

        if (currNode == p) foundP = true;
        if (currNode == q) foundQ = true;

        lca(currNode->left, p, q, foundP, foundQ, stackP, stackQ);
        lca(currNode->right, p, q, foundP, foundQ, stackP, stackQ);

        if (!foundP) stackP.pop();
        if (!foundQ) stackQ.pop();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> stackP, stackQ;
        bool foundP = false, foundQ = false;
        lca(root, p, q, foundP, foundQ, stackP, stackQ);

        // Ensure the stacks are of the same size by popping from the larger stack
        while (stackP.size() > stackQ.size()) stackP.pop();
        while (stackQ.size() > stackP.size()) stackQ.pop();

        // Find the common ancestor by comparing the elements from both stacks
        TreeNode* ans = nullptr;
        while (!stackP.empty() && !stackQ.empty()) {
            if (stackP.top() == stackQ.top()) {
                ans = stackP.top();
                break;
            }
            stackP.pop();
            stackQ.pop();
        }

        return ans;
    }
};