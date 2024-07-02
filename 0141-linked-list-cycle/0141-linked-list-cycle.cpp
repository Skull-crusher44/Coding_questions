/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  Solution 1 using set (TC = O(n) ||  SC = O(n))
// find and insert function will take O(1) TC
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // store the address of nodes that are visited
        set<ListNode*> visited;
        ListNode* curr = head;
        while (curr) {
            if (visited.find(curr) == visited.end()) { // if the curr address not found in set then it will point to end 
                visited.insert(curr);
                curr = curr->next;
            } else
                return 1;
        }
        return 0;
    }
};


//Solution 2
/*
Hash Table Method:
This approach involves storing visited nodes in a hash table. 
During traversal, if a node is encountered that already exists in the hash table, a cycle is confirmed.
------Using Unordered map
*/

class Solution {
public:
     bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;  
        ListNode*curr=head;

        while(curr)
        {
            if(mp[curr]==false) // if curr->address does not exist in map then we push curr address in map
            {
                mp[curr]=true;
                curr=curr->next;
            }
            else           // if curr->address exist in map then there exist a loop in linked list
            return true;
        }
        // means curr==null this shows that there exist a singly linked list and there is no loop
        return false;
    }
};

//Solution 3 (Floyd's Cycle-Finding Algorithm)
// using the concept of slow and fast pointer 
/*
Step 1: Initialise two pointers, `slow` and `fast`, to the head of the linked list.
 `slow` will advance one step at a time, while `fast` will advance two steps at a time.
  These pointers will move simultaneously.

Step 2: Traverse the linked list with the `slow` and `fast` pointers.
 While traversing, repeatedly move `slow` one step and `fast` two steps at a time.

Step 3: Continue this traversal until one of the following conditions is met:

`fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). 
In this case, there is no loop in the linked list ie. the linked list is linear, and the algorithm terminates by returning false.
`fast` and `slow` pointers meet at the same node. 
This indicates the presence of a loop in the linked list, and the algorithm terminates by returning `true`.*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        if (head == NULL)
            return false;
        while (fast != NULL && fast->next != NULL) {   // fast !=NULL will come first and then fast->next =NULL
                                                // kyunki agar fast null hua to fast->next(null ka next) runtime error dega 
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
