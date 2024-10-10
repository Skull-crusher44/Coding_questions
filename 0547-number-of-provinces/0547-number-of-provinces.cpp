class Solution {
public:
    // Perform BFS to visit all connected components
    int bfs(vector<vector<int>>& mat, int n, int node, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int j = 0; j < n; j++) {
                if (!visited[j] && mat[curr][j] == 1) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return 1;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(isConnected, n, i, visited);  // Use BFS to explore the connected components
                count++;
            }
        }
        return count;
    }
};
