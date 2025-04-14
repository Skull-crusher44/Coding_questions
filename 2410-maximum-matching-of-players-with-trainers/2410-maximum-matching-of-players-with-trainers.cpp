class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();

        int i=0,j=0;
        int count=0;
        while(i<n&&j<m){
            if(g[i]<=s[j]){
                i++;
                j++;
                count++;
            }
            else if(g[i]>s[i])  // when greed is more than capacity then increase the capacity
                j++;
        }
        return count;
    }
};