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
    
    int cal(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL) return head;
        int length = cal(head);
        
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        
        ListNode* prev = dummyhead;
        ListNode* curr, *nexx;
        while(k<=length)
        {
            curr = prev->next;
            nexx = curr->next;
            for(int i=1; i<k; i++)
            {
                curr->next = nexx->next;
                nexx->next = prev->next;
                prev->next = nexx;
                nexx = curr->next;
            }
            prev = curr;
            length -= k;
        }
        return dummyhead->next;
    }
};