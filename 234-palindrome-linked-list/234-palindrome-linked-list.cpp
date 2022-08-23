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
    bool isPalindrome(ListNode* head) 
    {
        if(head->next==NULL) return true;
        
        ListNode *slow=head, *fast=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *nex=NULL, *pre=NULL, *cur=slow;
        cur=cur->next;
        nex=cur->next;
        while(nex)
        {
            cur->next = pre;
            pre = cur;
            cur=nex;
            nex = nex->next;
        }
        cur->next = pre;
        slow->next = cur;
        
        while(cur)
        {
            if(cur->val != head->val) return false;
            cur=cur->next;
            head=head->next;
        }
        return true;       

    }
};