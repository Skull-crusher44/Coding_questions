class Solution {
public:
 bool dfs(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
        // Mark the current node as visited and add it to the recursion stack
        visited[start] = true;
        recStack[start] = true;

        for (auto ele : adj[start]) {
            if (!visited[ele]) {
                // Recur for DFS
                if (dfs(ele, adj, visited, recStack)) {
                    return true; // Cycle detected
                }
            } else if (recStack[ele]) {
                // If the node is in the recursion stack, we found a cycle
                return true; // Cycle detected
            }
        }

        // Remove the node from the recursion stack
        recStack[start] = false;
        return false; // No cycle detected
    }
    bool canFinish(int v, vector<vector<int>>& pre) {
        
        vector<bool> visited(v, false);
        vector<bool> recStack(v, false); // To keep track of nodes in the current path
        vector<vector<int>> adj(v); // Adjacency list
        int index = v - 1;

        // Create the adjacency list
        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        // Perform DFS for all vertices
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack)) {
                    return false; // Return an empty vector if a cycle is detected
                }
            }
        }
        return true;
    }
    
};