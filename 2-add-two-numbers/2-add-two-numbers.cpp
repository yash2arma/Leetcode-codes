class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum = 0, carry=0;
        ListNode* add = new ListNode();
        ListNode* temp = add;
        while(l1 || l2 || carry)     
        {
            sum = 0;
            if(l1!=NULL)
            {
                sum = l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return add->next;
        
    }
};


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
    
    
    
    
    
    
    
    
    
    
    
    
    
/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        
        ListNode* add = new ListNode();
        ListNode* res = add;
        int carry=0;
        
        while(l1!=NULL || l2!=NULL || carry)
        {
            int sum = 0;
            if(l1!=NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            add->next = node;
            add = add->next;

        } 
        return res->next;
    }
};
*/