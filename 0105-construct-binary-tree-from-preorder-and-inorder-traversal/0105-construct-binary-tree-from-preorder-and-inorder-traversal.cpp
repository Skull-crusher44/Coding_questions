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
TreeNode* createtree(vector<int>inorder,vector<int>preorder,int index, int start,int end)
    {
        if(start>end)
        return NULL;
        
        //create a node 
        TreeNode*root=new TreeNode(preorder[index]);
        
        // find the position of index element from preorder in inorder array 
        int pos;
        for(int i=start;i<end;i++)
        {
            if(inorder[i]==preorder[index])
            {
                pos = i;
                break;
            }
        }
        
        // recursion of left and right subtree 
        root->left = createtree(inorder,preorder,index+1,start,pos-1);
        root->right = createtree(inorder,preorder,index+(pos-start+1),pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createtree(inorder,preorder,0,0,inorder.size()-1);
    }
};