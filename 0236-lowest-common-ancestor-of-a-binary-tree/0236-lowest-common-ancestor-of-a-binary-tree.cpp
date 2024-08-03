/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode*root, TreeNode* p, TreeNode* q, TreeNode* &ans)
    {
        if(!root)return false ;

        // if(root==p||root==q)
        // return true;
        bool left=solve(root->left,p,q,ans);
        bool right=solve(root->right,p,q,ans);
        if(left&&right)
        {
            ans=root;
            return true;
        }
        else if((left&&!right)||(!left&&right))
        {
            if(root==p||root==q)
            {
                ans = root;  
            }
            return true;
        }
        else if(!left&&!right)
        {
            if(root==p||root==q)
            return true;
        }
        else
        return false;
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        solve(root,p,q,ans);
        return ans;
    }
};