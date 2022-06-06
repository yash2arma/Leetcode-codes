/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        
        if(tempA==NULL || tempB==NULL) return NULL;
        
        while(tempA!= tempB)
        {
            tempA==NULL ? tempA=headB : tempA=tempA->next;
            tempB==NULL ? tempB=headA : tempB=tempB->next;
        }
        
        return tempA;
    }
};