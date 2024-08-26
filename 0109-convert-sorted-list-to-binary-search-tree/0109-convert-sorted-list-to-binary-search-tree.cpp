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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*convert_to_tree(vector<int>&list,int start,int end)
    {
        if(start>end)
        return NULL;
        int mid =start+(end-start)/2;
        TreeNode*curr=new TreeNode(list[mid]);
        curr->left=convert_to_tree(list,start,mid-1);
        curr->right=convert_to_tree(list,mid+1,end);
        return curr;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>list;
        while(head)
        {
            list.push_back(head->val);
            head=head->next;
        }
        return convert_to_tree(list,0,list.size()-1);
    }
};