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
    int find(TreeNode* root,int &sum)
    {
        if(!root)return 0;
        // if(!root->left&&!root->right)
        // return root->val;

        int left=find(root->left,sum);
        int right=find(root->right,sum);
        //sum = max(sum,root->val+left+right);
        // sum=max(sum,left);
        // sum=max(sum,right);
        sum=max(sum,root->val);
        sum=max(sum,left+root->val);
        sum=max(sum,right+root->val);
        sum=max(sum,left+root->val+right);
        
        return max(max(left,right)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        int val = find(root,sum);
        if(root->left&&root->right)
        return sum;
        return max(sum,val);
    }
};