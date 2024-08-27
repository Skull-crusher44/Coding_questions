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
        void swap(TreeNode* t1, TreeNode* t2) {
        int val = t1->val;
        t1->val = t2->val;
        t2->val = val;
    }
    void tree_to_arr(TreeNode*root,vector<TreeNode*>&ino)
    {
        if(!root)return;
        tree_to_arr(root->left,ino);
        ino.push_back(root);
        tree_to_arr(root->right,ino);
    }
    void recoverTree(TreeNode* root) {
    vector<TreeNode*>ino;
    tree_to_arr(root,ino);
    TreeNode* first=NULL,*second=NULL;
    for(int i=1;i<ino.size();i++)
    {
        if(ino[i]->val<ino[i-1]->val)
        {
            if(first==NULL)
            {
                first=ino[i-1];
                second=ino[i];
            }
            else
            {
                second=ino[i];
            }  
        }
    }
    swap(first,second);
    }

};



    // This method is wrong because jab hme wrong node milege to uske baad compression of range change ho jayega  
    // void swap(TreeNode* t1, TreeNode* t2) {
    //     int val = t1->val;
    //     t1->val = t2->val;
    //     t2->val = val;
    // }

    // void fix(TreeNode* root, long min, long max, vector<TreeNode*>& ans) {
    //     if (!root) return;
    //     if (root->val <= min || root->val >= max) 
    //         ans.push_back(root);
    //     fix(root->left, min, root->val, ans);
    //     fix(root->right, root->val, max, ans);
    // }
    // void recoverTree(TreeNode* root) {
    //     vector<TreeNode*> ans;
    //     TreeNode*temp=root;
    //     fix(temp, LONG_MIN, LONG_MAX, ans);
        
    //     if (ans.size() == 1)  
    //         swap(ans[0], root);
    //     else if (ans.size() > 1)
    //         swap(ans[0], ans[1]);
    // }
