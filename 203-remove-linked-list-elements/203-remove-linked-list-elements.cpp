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
    /*ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head) return head;
        
        ListNode* newhead = new ListNode();
        newhead->next = head;
        ListNode* prev = newhead;
        
        while(head)
        {
            if(head->val==val)
                prev->next = head->next;
            
            else
                prev = prev->next;
            
                
            head = head->next;
                
        }
        return newhead->next;;
        
    }
    */
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head) return head;
        
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        head = newhead;
        
        while(head && head->next)
        {
            if(head->next->val==val)
                head->next = head->next->next;    
            else
                head = head->next;
        }
        return newhead->next;
        
    }
};