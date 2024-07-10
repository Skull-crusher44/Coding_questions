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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*temp;
        
        ans.push_back({root->val});
        while(!q.empty())
        {
            vector<int>v;
            temp = q.front();
            if(temp->left)
                {
                    q.push(temp->left);
                    v.push_back(temp->left->val);
                }
            if(temp->right)
                {
                    q.push(temp->right);
                    v.push_back(temp->right->val);
                }
                if(v.size()!=0)
                ans.push_back(v);
            q.pop();
        }
        return ans;
    }
};