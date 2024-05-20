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
      // to count the total no of nodes 
        while(curr)
        {
            count++;
            curr=curr->next;
        }
        int from_start=count-n;
      //from_start represent position of node from starting after which we have to delete the next node 
        if(from_start==0)
        {
            
            head=head->next;
            return head;
        }
        curr=head;
        while(--from_start)
        {
            curr=curr->next;
        }
      //curr pointer pointing the node one step before the deleted node 
        
        curr->next=curr->next->next;
        
        return head;
    }
};
