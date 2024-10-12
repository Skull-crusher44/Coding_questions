class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
     vector<int>adj[n];
     for(int i=0;i<relations.size();i++)
     {
        adj[relations[i][0]-1].push_back(relations[i][1]-1);
     }
     
     vector<int> in_degree(n, 0);
     vector<int>ans=time;//maximum time to complete till current courses
    for (int i = 0; i < n; i++) 
    {
        for (auto neighbor : adj[i]) 
        {
            in_degree[neighbor]++;
        }
    }
    
    // Step 2: Initialize the queue and add all vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) 
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

        // For each adjacent vertex of the current vertex
        for (auto neighbor : adj[current]) 
        {
            // Reduce the in-degree of the neighbor by 1
            in_degree[neighbor]--;
            ans[neighbor] = max(ans[neighbor],ans[current]+time[neighbor]);
            
            // If the in-degree of neighbor becomes 0, add it to the queue
            if (in_degree[neighbor] == 0) 
            {
                q.push(neighbor);
            }
        }
    }
        int maxi=INT_MIN;
        for(int i =0 ; i < n ; i++)
        {
            maxi=max(ans[i],maxi);
        }
        return maxi;
    }
};