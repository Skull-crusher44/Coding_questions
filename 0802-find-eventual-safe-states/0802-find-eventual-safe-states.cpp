class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            //reverse the graph 
            //Apply the toposort
            //return toposort array
        int v=graph.size();
        vector<int>adjrev[v];
        for(int i=0;i<v;i++)
        {
            for(auto ele:graph[i])
            {
                adjrev[ele].push_back(i);
            }
        }

    vector<int> in_degree(v, 0);
    vector<int>ans;
    for (int i = 0; i < v; i++) 
    {
        for (auto neighbor : adjrev[i]) 
        {
            in_degree[neighbor]++;
        }
    }
    
    // Step 2: Initialize the queue and add all vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < v; i++) 
    {
        if (in_degree[i] == 0) 
        {
            q.push(i);
        }
    }
    
    // Step 3: Perform BFS-like traversal to create the topological order
    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        ans.push_back(current);
        // For each adjacent vertex of the current vertex
        for (auto neighbor : adjrev[current]) 
        {
            // Reduce the in-degree of the neighbor by 1
            in_degree[neighbor]--;
            
            // If the in-degree of neighbor becomes 0, add it to the queue
            if (in_degree[neighbor] == 0) 
            {
                q.push(neighbor);
            }
        }
    }
       sort(ans.begin(),ans.end());
       return ans;
    }
};