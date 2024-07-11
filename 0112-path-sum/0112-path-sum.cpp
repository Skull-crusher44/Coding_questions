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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
        return false;
        if(!root->left&&!root->right)
        {
            return(targetSum==root->val);
        }
        bool left_exists=hasPathSum(root->left,targetSum-root->val);
        bool right_exists=hasPathSum(root->right,targetSum-root->val);
        return (left_exists||right_exists);
    }
};