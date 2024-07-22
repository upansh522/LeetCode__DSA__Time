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
    int key = -1;
    TreeNode* lca = new TreeNode();

    bool help(TreeNode * root , string& s)
    {

        if (root == nullptr)
        {
            return false;
        }

        if (root->val == key)
        {
            return true;
        }

        
        bool a = help(root->right,s);
        bool b = help(root->left,s);
        s += "L";
        if (!b)
        {
           s.pop_back();
        }

        s += "R";
        if ( !a)
        {
            s.pop_back();
        }

        return a||b;
         
    }
    bool find(TreeNode * root , TreeNode * sec  ,int b)
    {  
        if (root == nullptr) return false;
        if (root == sec)
        {
            return false;
        }

        if (root->val == b) return true;

        return find(root->left , sec,b)||find(root->right,sec,b);
    }
    bool func(TreeNode * root , vector<TreeNode*>&temp)
    {  
    if (root == NULL)
       {
        return false;
       }

    
     if (root->val == key)
       {
        temp.push_back(root);
        return true;
       }

     temp.push_back(root);
     if (!func(root->left,temp) && !func(root->right,temp))
       {
          temp.pop_back();
          return false;
       }


       return true;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {

        if (startValue == destValue)return "";
        vector<TreeNode*>v1,v2;

        key = startValue;
        func(root,v1);

        
        int i = v1.size()-1;
        int j = v2.size()-1;

        TreeNode* lca = new TreeNode();

        unordered_set<TreeNode*>st(v2.begin(),v2.end());
         TreeNode* sec = new TreeNode();
        while(i>=0)
        {    
            if(find(v1[i],sec,destValue))
            {
                lca = v1[i];
                break;
            }
            sec = v1[i];
            i--;
            
        }
         
         cout<<lca->val;
       

        string part1="",part2="";
        key = startValue;
        help(lca,part1);
        

        key = destValue;
        help(lca,part2);

        for(auto &it : part1)
        {   
            it  = 'U';
        }

        reverse(part2.begin(),part2.end());

        string ans = part1 + part2;

        return ans;

    }
};