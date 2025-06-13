
//  // problem = this code is not able to sort elements on same vertical and horizontal level
// class Solution {
// public:
//     void find(TreeNode*root,int &l,int &r, int pos)
//     {
//         if(!root)return;
//         l=min(l,pos);
//         r=max(r,pos);
//         find(root->left,l,r,pos-1);
//         find(root->right,l,r,pos+1);
//     }
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         int l=0,r=0;
//         find(root,l,r,0);
//         vector<vector<int>>ans(r-l+1);
//         queue<pair<TreeNode*,pair<int,int>>>q;  //q(node , (vertical level ,horizontal level))
//         q.push({root,{-1*l,0}});   

//         while(!q.empty())
//         {
//             TreeNode*curr=q.front().first;
//             int vl=q.front().second.first;
//             int hl=q.front().second.first;
//             q.pop();
//             ans[vl].push_back(curr->val);
            
//             // if(ans[vl].size()>=1)
//             // {
//             //     int last=ans[vl][ans[vl].size()-1];
//             //     int last_second=ans[vl][ans[vl].size()-2];
//             //     if(last_second>last)
//             //     swap(ans[vl][ans[vl].size()-1],ans[vl][ans[vl].size()-2]);
//             // }
//             if(curr->left)q.push({curr->left,{vl-1,hl+1}});
//             if(curr->right)q.push({curr->right,{vl+1,hl+1}});

//         }

//         return ans;
//     }
// };




class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) 
        {
            map<int, multiset<pair<int, int>>> mp; // [x][y, val]
            traverse(root, 0, 0, mp);
            vector<vector<int>> res;
            for(auto& [x, st] : mp)
            {
                res.push_back({});
                for(auto& [y, val] : st) res.back().push_back(val);
            }
            return res;
        }
        
    protected:
        void traverse(TreeNode* node, int x, int y,  map<int, multiset<pair<int, int>>>& mp)
        {
            if(!node) return;
            mp[x].insert({y, node->val});
            traverse(node->left, x-1, y+1, mp);
            traverse(node->right, x+1, y+1, mp);
        }
};