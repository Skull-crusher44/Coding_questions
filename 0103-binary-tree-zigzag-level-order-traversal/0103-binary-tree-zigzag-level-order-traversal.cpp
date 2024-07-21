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
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans; 
    queue<TreeNode*> q; // Queue to help with level order traversal.
    
    if (!root) return ans; // If the tree is empty, return an empty result.
    
    q.push(root); // Push the root node to start the level order traversal.
    
    bool LtoR = true; // Boolean flag to determine the direction of traversal, starting with Left to Right.
    
    while (!q.empty()) { 
        int size = q.size(); // Get the number of nodes at the current level.
        vector<int> v(size); // Create a vector to store values of the current level.
        
        for (int i = 0; i < size; i++) { // Iterate through all nodes at the current level.
            TreeNode* curr = q.front(); // Get the front node from the queue.
            q.pop(); 
            
            // Determine the index in the vector where the current node's value should go.
            int index = LtoR ? i : size - 1 - i; 
            v[index] = curr->val; // Assign the node's value to the determined index.
            
            // If the current node has a left child, add it to the queue for the next level.
            if (curr->left) q.push(curr->left);
            
            // If the current node has a right child, add it to the queue for the next level.
            if (curr->right) q.push(curr->right);
        }
        
        ans.push_back(v); 
        
        LtoR = !LtoR; // Toggle the direction for the next level.
    }
    
    return ans; 
}

};