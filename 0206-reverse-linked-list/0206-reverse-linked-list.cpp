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

class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *front=head,*curr=head;
        ListNode* prev=NULL;
        while(curr){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }   
        return prev;
    }
};
// class Solution {
// public:

//     ListNode* reverse(ListNode* head,ListNode* prev,ListNode*curr)
//     {
//         if(curr==NULL)
//         return prev;
//         ListNode*temp=curr->next;
//         curr->next=prev;
//         return reverse(head, curr,temp);
//     }


//     ListNode* reverseList(ListNode* head) {
        
//         ListNode*curr=head;
//         ListNode* prev=NULL;
//         head=reverse(head,prev,curr);
//         return head;
        
//     }
// };