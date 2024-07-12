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
    bool symmetry(TreeNode*r1,TreeNode*r2)//same as "identical trees "in GFG
    {
        if(!r1&&!r2)  //Both are NULL
        return true;
        if((r1&&!r2)||(!r1&&r2))//one of them is not NULL
        return false;
        if(r1->val!=r2->val)
        return false;
        return (symmetry(r1->left,r2->right)&&symmetry(r1->right,r2->left));
        /*comparing left subtree's left child with right subtree's right child 
        --AND-- 
        comparing left subtree's right child with right subtree's left child*/
    }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)  //Tree is empty 
        return true;
        return symmetry(root->left,root->right);       
    }
};