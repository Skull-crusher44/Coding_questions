class Solution {
public:
//using BFS
    bool check(int start,vector<vector<int>>& graph,vector<int>&color)
    {   queue<int>q;
        q.push(start);
    	color[start]=0;
        while(!q.empty())
	    {
	        int curr=q.front();
	        q.pop();
	        for(auto ele:graph[curr])
	        {
	            if(color[ele]==-1)
	            {
	                color[ele]=(color[curr]+1)%2;
	                q.push(ele);
	            }
	            else
	            {
	                if(color[curr]==color[ele])
	                return false;
	            }
	        }
	    }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();
          vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1 && !check(i,graph,color))
	        {
	            return false;
	        }
	    }
	    return true;
    }
};