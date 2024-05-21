/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         Node*root=new Node(0);//curr==pointer for iterating on original list 
        Node*temp=root;     // temp==pointer for iterating on cloned list 
        Node*curr=head;
        while(curr)
        {
            temp->next=new Node(curr->val);
            curr=curr->next;
            temp=temp->next;
        }
        temp=root;
        root=root->next;
        delete(temp);
    
        curr=head;
        temp=root;
        
        // hashmap will map the original and cloned lists address
        unordered_map<Node*,Node*>mp;
        while(curr)
        {
            mp[curr]=temp;
            temp=temp->next;
            curr=curr->next;
        }
        //100--500
        //200--600
        //300--700...
        curr=head;
        temp=root;
        
        // assign random pointer 
        while(curr)
        {
            Node*mapped_node=curr->random;
            temp->random=mp[mapped_node] ;    // mp[mapped_node] will give coresponding node in cloned list
            temp=temp->next;            //which will be assigned in temp->arb
            curr=curr->next;
        }
        return root;
    }
};