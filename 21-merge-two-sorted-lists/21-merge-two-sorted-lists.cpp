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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
		//if any of the list is null then we return other list
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
		//we always carried l1 as list of small value for that we used swap operation
		//if l2 value is lesser than l1 value then we swap l1 with l2.
        if(l1->val > l2->val) swap(l1, l2);
        
		//assign l1 to result node.
		ListNode* res = l1;
        
		//we continue the process until one of them gets null
        while(l1!= NULL && l2!= NULL)
        {
			//use temp to store pointer of current node
            ListNode *temp = NULL;
			
			//if l1 value is lesst than l2 value we do the following operation
            while(l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
			
			//if l2 value is less than l1 value we assign temp(current node) next to l2 and then swap both the nodes.
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }
};