/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prevNode,*currNode,*nextNode;
        vector<int>ans;

        currNode=head->next;
        prevNode=head;
        if (currNode==nullptr)
        return {-1,-1};
        int pos=1;

        nextNode=currNode->next;
        while(nextNode!=nullptr)
        {
            if ((currNode->val>nextNode->val && currNode->val>prevNode->val) || (currNode->val<nextNode->val && currNode->val<prevNode->val))
            {
                ans.push_back(pos);
            }
            prevNode=currNode;
            currNode=nextNode;
            nextNode=nextNode->next;
            pos++;
        }

        
        if (ans.size()<2)
        {
            return {-1,-1};
        }
        int minele=INT_MAX,maxele=ans[ans.size()-1]-ans[0];
        for (int i=0;i<ans.size()-1;i++)
        {
            minele=min(minele,ans[i+1]-ans[i]);
        }

    

        return {minele,maxele};
    }
};