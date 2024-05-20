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
    ListNode* merge(ListNode*list1,ListNode*list2)
    {
        ListNode*temp;
        ListNode*dummy=new ListNode();
        temp=dummy;
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        // we have reached at end of one of list
        if(list1)
        {
            temp->next=list1;
        }
        if(list2)
        {
            temp->next=list2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
         ListNode *fast = head->next->next, *slow = head;
        while(fast && fast->next) 
        {
        fast = fast->next->next;
        slow = slow->next;
        }
        ListNode*right=sortList(slow->next);
        slow->next=NULL;
        ListNode*left=sortList(head);
        return merge(left,right);
        
    }
};