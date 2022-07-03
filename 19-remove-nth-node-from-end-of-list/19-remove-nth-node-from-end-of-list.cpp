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
    ListNode* removeNthFromEnd(ListNode* head, int K) 
    {
        if(head==NULL || K==0) return head;
        int n=0;
        ListNode* temp = head;
        while(temp)
        {
            n++;
            temp = temp->next;
        }

        K = n-K;
        temp = head;
        cout<<n<<" "<<K<<endl;
        ListNode* prev = NULL;
        while(K--)
        {
            prev = temp;
            temp = temp->next;
        }
        if(prev!=NULL)
            prev->next = temp->next;
        else
            head=head->next;
        return head;
        
    }
};