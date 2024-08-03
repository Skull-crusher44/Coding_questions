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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        if(root==p||root==q)
        return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(right&&left)
        return root;
        if(left&&!right)
        return left;
        if(right&&!left)
        return right;
        else
        return NULL;
    }
};


/*
//MY SOLUTION 
class Solution {
public:
    bool solve(TreeNode*root, TreeNode* p, TreeNode* q, TreeNode* &ans)
    {
        if(!root)return false ;

        // if(root==p||root==q)
        // return true;
        bool left=solve(root->left,p,q,ans);
        bool right=solve(root->right,p,q,ans);
        // left aur right dono me match mila to return true;
        if(left&&right)
        {
            ans=root;
            return true;
        }
        else if((left&&!right)||(!left&&right))  //left aur right me se agar koi ek exist kare 
        {
            if(root==p||root==q)// to check karo ki root to p or q nhi
            {
                ans = root;  
            }
            return true;// left aur right me se koi exist kar rha ha to return true hoga ignoring above if condn
        }
        else if(!left&&!right)  // left aur right dono exist na kare to check karo ki root to match nhi karta 
        {
            if(root==p||root==q)
            return true;
        }
        return false;// agar dono false ha aur root bhi match nhi karta to return false 

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        solve(root,p,q,ans);
        return ans;
    }
};
//Babbar solution
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if the current node is NULL, return NULL
    if (!root) return NULL;

    // If the current node is either p or q, return the current node
    if (root == p || root == q) return root;

    // Recursively search for LCA in the left subtree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);

    // Recursively search for LCA in the right subtree
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are non-NULL, it means p and q are found in different subtrees
    // Hence, the current node is their lowest common ancestor
    if (left && right) return root;

    // If only one of the left or right is non-NULL, return the non-NULL one
    // This means both p and q are found in the same subtree
    if (left) return left;
    if (right) return right;

    // If both left and right are NULL, return NULL
    return NULL;
}
       3
      / \
     5   1
    / \ / \
   6  2 0  8
     / \
    7   4
Find the lowest common ancestor of nodes 5 and 1:

Start at root node 3.
Check if 3 is either 5 or 1 (it's not).
Recursively search the left subtree of 3 for LCA of 5 and 1.
At node 5 (left child of 3), check if 5 is either 5 or 1 (it is 5).
Return node 5 as the LCA found in the left subtree.
Recursively search the right subtree of 3 for LCA of 5 and 1.
At node 1 (right child of 3), check if 1 is either 5 or 1 (it is 1).
Return node 1 as the LCA found in the right subtree.
Since both left and right subtrees returned non-NULL values (5 and 1), return node 3 as the LCA of nodes 5 and 1.
The final LCA is node 3.

       3
      / \
     5   1
    / \ / \
   6  2 0  8
     / \
    7   4
Start at Root Node 3:

Check if 3 is either 5 or 4 (it's not).
Recursively search the left subtree of 3 for LCA of 5 and 4.
Move to Node 5 (Left Child of 3):

Check if 5 is either 5 or 4 (it is 5).
Return node 5 as the LCA found in the left subtree of 3.
Back to Node 3, Search Right Subtree:

Recursively search the right subtree of 3 for LCA of 5 and 4.
Move to Node 1 (Right Child of 3):

Check if 1 is either 5 or 4 (it's not).
Recursively search the left subtree of 1 for LCA of 5 and 4.
Move to Node 0 (Left Child of 1):

Check if 0 is either 5 or 4 (it's not).
Both left and right children of 0 are NULL.
Return NULL as no LCA found in the left subtree of 1.
Move to Node 8 (Right Child of 1):

Check if 8 is either 5 or 4 (it's not).
Both left and right children of 8 are NULL.
Return NULL as no LCA found in the right subtree of 1.
Back to Node 1, Both Subtrees Returned NULL:

Return NULL as no LCA found in the subtrees of 1.
Back to Node 3, Combine Results:

Left subtree of 3 returned 5.
Right subtree of 3 returned NULL.
Since only the left subtree returned a non-NULL result, return node 5 as the LCA of nodes 5 and 4.*/