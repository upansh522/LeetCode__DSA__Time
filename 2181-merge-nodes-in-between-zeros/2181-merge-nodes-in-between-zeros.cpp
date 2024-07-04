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
    ListNode* mergeNodes(ListNode* head) {
        if (head==nullptr)
        return nullptr;
        ListNode* temp=head->next;
        ListNode* ans=head;
        int count=0;
        int sum=0;
        while(temp!=nullptr)
        {
            if (temp->val==0)
            {
                ans->val=sum;
                sum=0;
                ans=ans->next;
                count++;
            }
            sum+=temp->val;
            temp=temp->next;
        }     

        temp=head;
        while(count>1)
        {
            temp=temp->next;
            count--;
        }
        temp->next=nullptr;

        return head;
    }
};