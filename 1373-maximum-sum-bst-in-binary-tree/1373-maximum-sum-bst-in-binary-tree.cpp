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
    class box{
        public:
        bool bst;
        int sum;
        int min,max;
        box(){
            bst=true;
            sum=0;
            min=INT_MAX;
            max=INT_MIN;
        }
    };
    box* solve(TreeNode*root,int &max_sum)
    {
        //if root does not exist   
        if(!root)
        {
            return new box();
        }         

        box*left=solve(root->left,max_sum);
        box *right=solve(root->right,max_sum);

        box *temp=new box();

        if((left->bst&&right->bst)&&(root->val > left->max && root->val < right->min ))
        {
            temp->bst=true;
            temp->sum=left->sum+right->sum+root->val;
            temp->min=min(left->min,root->val);// agar left exist kara to left->min hi mera min ha nahi to root->data hi mera minimum value h 
            temp->max=max(root->val,right->max);// agar right exist kara to right->max hi mera max ha nahi to root->data hi mera maximum value h 
            
        }  
        else
        {
            temp->bst=false;
            
        }              
            max_sum=max(max_sum,temp->sum);
            return temp;
    }
    int maxSumBST(TreeNode* root) {
        int max_sum=INT_MIN;
        solve(root,max_sum);
        return max_sum;
    }
};