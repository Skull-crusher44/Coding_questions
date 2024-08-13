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
    TreeNode* bst(int lower,int upper,vector<int>&preorder,int &index)
    {
        if(index==preorder.size()||preorder[index]<lower||preorder[index]>upper)
        return NULL;
        TreeNode* curr=new TreeNode(preorder[index++]);
        curr->left=bst(lower,curr->val,preorder,index);
        curr->right=bst(curr->val,upper,preorder,index);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return bst(INT_MIN,INT_MAX,preorder,index);
    }
};