/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createtree(vector<int> inorder, vector<int> preorder, int index,
                         int start, int end,unordered_map<int,int>mp) {
                            // index = first element of preoder vec
        if (start > end)
            return NULL;

        // create a node
        TreeNode* root = new TreeNode(preorder[index]);

        // find the position of index element from preorder in inorder array
        int pos = mp[preorder[index]];
    

        // recursion of left and right subtree
        root->left = createtree(inorder, preorder, index + 1, start, pos - 1,mp);
        root->right = createtree(inorder, preorder, index + (pos - start + 1),
                                 pos + 1, end,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int ,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return createtree(inorder, preorder, 0, 0, inorder.size() - 1,mp);
    }
};