class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int k) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    //make adjacency List
    vector<pair<int,int>>adj[V+1];
    for(int i =0 ; i < times.size() ; i++)
    {
       adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    // Distance vector to store the shortest distances, initialized to infinity
    vector<int> dist(V+1, INT_MAX);
    
    // Distance to the source node is 0
    dist[k] = 0;
    
    // Push the source node into the priority queue
    pq.push({0, k});  // {distance, node}
    
    // While there are nodes to process
    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        
        // Traverse all adjacent nodes
        for (auto it : adj[currNode]) {
            int neighbour = it.first;
            int weight = it.second;
            
            // Relaxation: check if we found a shorter path to the neighbor
            if (dist[neighbour] > currDist + weight) {
                dist[neighbour] = currDist + weight;
                // Push the neighbor into the queue with its updated distance
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    
    // Convert unreachable distances (INT_MAX) to -1
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
            return -1;
        }
    }
    int maxi=INT_MIN;
    for(int i =1 ; i <= V ; i++)
    {
        maxi=max(dist[i],maxi);
    }
    return maxi;
    }
};