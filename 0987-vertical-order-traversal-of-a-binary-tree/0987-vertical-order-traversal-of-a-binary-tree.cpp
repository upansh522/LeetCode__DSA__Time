/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> qu;
        qu.push({root, {0, 0}});

        while (!qu.empty()) {
            int size = qu.size();
            pair<TreeNode*, pair<int, int>> currNode;

            for (int i = 0; i < size; i++) {
                currNode = qu.front(); qu.pop();
                int x = currNode.second.first;
                int y = currNode.second.second;
                mp[x][y].insert(currNode.first->val);

                if (currNode.first->left != nullptr)
                    qu.push({currNode.first->left, {x - 1, y + 1}});

                if (currNode.first->right != nullptr)
                    qu.push({currNode.first->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto i : mp) {
            vector<int> temp;
            
            for(auto q: i.second)
            {
                for (auto itt:q.second){
                    temp.push_back(itt);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};