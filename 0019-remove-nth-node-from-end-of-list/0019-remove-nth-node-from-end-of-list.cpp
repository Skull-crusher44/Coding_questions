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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;
        
        //The fast-moving pointer will initially be exactly N nodes ahead of the slow-moving pointer.

        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        // if fast==NULL means we have to remove 1 st node 
        if(fast==NULL)
        return head->next;
        
        //After which, both of them will move one step at a time until fast pointer reaches last node 
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        //When the fast pointer reaches the last node, i.e., the L-th node,
        // the slow is guaranteed to be at the (L-N)-th node, where L is the total length of the linked list.
        ListNode*temp=slow->next;
        slow->next=slow->next->next;
        delete (temp);
        return head;
    }
};