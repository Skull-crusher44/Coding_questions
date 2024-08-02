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
    void node_to_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp= q.front();
            q.pop();
            if(temp->left)
            {
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
    }
    void cal_distance(TreeNode*root,int k,vector<int>&ans,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        unordered_map<TreeNode*,bool>visited;
        visited[root]=true;

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp= q.front().first;
                int dist=q.front().second;
                q.pop();

                if(dist==k)
                {
                    ans.push_back(temp->val);
                }
                if(temp->left&&!visited[temp->left])
                {
                    
                    visited[temp->left]=1;
                    q.push({temp->left,dist+1});
                }
                if(temp->right&&!visited[temp->right])
                {
                    visited[temp->right]=1;
                    q.push({temp->right,dist+1});
                } 
                if(mp[temp]&&!visited[mp[temp]])
                {
                    visited[mp[temp]]=1;
                    q.push({mp[temp],dist+1});
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root]=NULL;
        node_to_parent(root,mp);

        cal_distance(target,k,ans,mp);
        return ans;
    }
};