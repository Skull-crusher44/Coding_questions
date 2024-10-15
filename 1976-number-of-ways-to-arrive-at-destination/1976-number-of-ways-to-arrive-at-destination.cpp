class Solution {
public:
    int countPaths(int v, vector<vector<int>>& roads) {
    // Create adjacency list
    vector<pair<int, int>> adj[v];
    for (const auto& road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]}); // Since the roads are bidirectional
    }

    // Min-heap priority queue, where each pair is {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0}); // {distance, start node}

    vector<int> dist(v, INT_MAX); // Distance array
    dist[0] = 0;

    vector<int> ways(v, 0); // To count the number of ways to reach each node
    ways[0] = 1; // There's one way to reach the start node

    while (!q.empty()) {
        int currDist = q.top().first;
        int currNode = q.top().second;
        q.pop();

        // If the popped distance is already greater than the current known distance, skip
        if (currDist > dist[currNode]) {
            continue;
        }

        // Explore the neighbors of the current node
        for (auto& [neighbor, weight] : adj[currNode]) {
            int newDist = currDist + weight;

            // If a shorter path to the neighbor is found
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                q.push({newDist, neighbor});
                ways[neighbor] = ways[currNode]; // Set the number of ways to the current node
            }
            // If another path with the same shortest distance is found
            else if (newDist == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[currNode]) % 1000000007; // Add ways
            }
        }
    }

    // Return the number of ways to reach the last node (v-1)
    return ways[v-1];
}

};