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
        ListNode*curr=head;
        int count=0;
        while(curr)
        {
            count++;
            curr=curr->next;
        }
        int from_start=count-n-1;
        if(from_start==-1)
        {
            
            head=head->next;
            return head;
        }
        curr=head;
        while(from_start--)
        {
            curr=curr->next;
        }
        
        curr->next=curr->next->next;
        
        return head;
    }
};