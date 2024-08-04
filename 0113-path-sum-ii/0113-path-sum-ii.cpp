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
    void find(TreeNode*root,int target,vector<int>&temp,vector<vector<int>>&ans,int sum)
    {
        if(!root)return ;
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left&&!root->right)
        {
            if(target==sum)
            {
                ans.push_back(temp);
            }
        }
        else
        {
            find(root->left,target,temp,ans,sum);
            find(root->right,target,temp,ans,sum);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        find(root,targetSum,temp,ans,0); 
        return ans; 
    }
};