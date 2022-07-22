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
    ListNode* partition(ListNode* head, int x) 
    {
        vector<int> lesser, greater;
        
        ListNode* temp = head;
        while(head)
        {
            if(head->val < x)
                lesser.push_back(head->val);
            else
                greater.push_back(head->val);
            
            head = head->next;
        }
        
        head = temp;
        int count=0;
        while(head)
        {
            if(count<lesser.size())
                head->val = lesser[count];
            else
                head->val = greater[count-lesser.size()];
            count++;
            head = head->next;
            
        }
        return temp;
    }
};