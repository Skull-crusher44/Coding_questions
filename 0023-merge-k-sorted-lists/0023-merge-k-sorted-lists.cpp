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

   ListNode*merge(ListNode*list1,ListNode*list2)
    {
        ListNode*tail=new ListNode(0);
        ListNode*head=tail;
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                tail->next=list1;
                list1=list1->next;
                tail=tail->next;
            }
            else
            {
                tail->next=list2;
                list2=list2->next;
                tail=tail->next;
            }
        }
        if(list1)
        {
            tail->next=list1;   
        }
        if(list2)
        {
            tail->next=list2;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        return NULL;

        int i=0;
        // 1--- check element exists or not in vector
        //2--- then check ->that value is null or not (it swap the conditions it will not work for lists=[[]])
        while(i<lists.size()&&lists[i]==NULL)
        {
            i++;
        }
        // if i==lists.size()-> this means all elements of vector are null ( lists =[[],[],[],[]] )
        if(i==lists.size())                                                        // 0  1  2  3 i
        {
            return NULL;
        }
        //merge two list again and again 
        // head will store the head pointer of two merged list then head will be merged to next list
        ListNode*head=lists[0];
        for(int i=0;i<lists.size()-1;i++)
        {
            head=merge(head,lists[i+1]);
        }
        return head;
    }
};
