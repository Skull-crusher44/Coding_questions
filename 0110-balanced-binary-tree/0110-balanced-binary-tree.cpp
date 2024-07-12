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
    int solve(TreeNode* root,bool &ans)
    {
        if(!root)
        return 0;
        int l_height=solve(root->left,ans);
        int r_height = solve(root->right,ans);

        int height_diff=l_height-r_height;
        if(height_diff>1||height_diff<-1)
        ans=false;
        return (max(l_height,r_height)+1);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        solve(root,ans);
        return ans;
    }
};