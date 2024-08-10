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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else
        {
            //leaf node delete karni ho to
            if(!root->left&&!root->right)
            {
                delete root;
                return NULL;
            } 
            // agar dono exist kare 
            if(root->left&&root->right)
            {
                TreeNode*parent=root;
                TreeNode*child=root->left;/// find the rightmost node in left subtree kyuki vo child root se just small hoga 
                while(child->right)
                {
                    parent = child;
                    child=child->right;
                }
                if(parent!=root)
                {
                    parent->right=child->left; //child ka right to exist karega nahi
                    root->left=child->left;
                    root->right=child->right;
                    delete root;
                    return child;
                }
                else// agar parent ka child hi key node nikla (edge case)
                {
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }   
            // sirf right node 
            if(root->right)
            {
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            //sirf left node 
            if(root->left)
            {
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }
        }
        return NULL;
    }
};