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
    void  update(TreeNode*root,int &sum)
    {
        if(!root)return ;
        update(root->right,sum);
        root->val=sum+root->val;
        sum =root->val;
        update(root->left,sum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        update(root,sum);
        return root;

    }
};