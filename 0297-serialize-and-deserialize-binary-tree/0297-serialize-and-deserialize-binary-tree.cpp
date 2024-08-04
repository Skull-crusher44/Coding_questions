/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 /*
                             1
                           / \
                          2   3
                             / \
                            4   5
    Serialization
    Start at the root node 1.
    Add 1, to the result string.
    Move to the left child 2.
    Add 2, to the result string.
    Both children of 2 are NULL, so add null,null, to the result string.
    Backtrack to 1 and move to the right child 3.
    Add 3, to the result string.
    Move to the left child 4.
    Add 4, to the result string.
    Both children of 4 are NULL, so add null,null, to the result string.
    Backtrack to 3 and move to the right child 5.
    Add 5, to the result string.
    Both children of 5 are NULL, so add null,null, to the result string.
    Final serialized string: "1,2,null,null,3,4,null,null,5,null,null,"

    Deserialization
    Initialize a queue with the elements of the serialized string: ["1", "2", "null", "null", "3", "4", "null", "null", "5", "null", "null"].
    Start with the root node 1.
    Dequeue 1 and create a new TreeNode with value 1.
    Dequeue 2 and create the left child of 1 with value 2.
    Dequeue null for the left child of 2, which is NULL.
    Dequeue null for the right child of 2, which is NULL.
    Dequeue 3 and create the right child of 1 with value 3.
    Dequeue 4 and create the left child of 3 with value 4.
    Dequeue null for the left child of 4, which is NULL.
    Dequeue null for the right child of 4, which is NULL.
    Dequeue 5 and create the right child of 3 with value 5.
    Dequeue null for the left child of 5, which is NULL.
    Dequeue null for the right child of 5, which is NULL.
*/
class Codec {
public:
    
    void buildString(TreeNode* root, string &res)
    {
        if(root == NULL)
        {   res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    string serialize(TreeNode* root) 
    { 
        string res = "";
        buildString(root, res);
        return res;
    }
    
    TreeNode* buildTree(queue<string> &q) 
    {
        string s = q.front();
        q.pop();
        
        if(s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) 
    {
        string s = "";
        queue <string> q;
        
        for(char c: data) 
        {
            if(c == ',') 
            {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));