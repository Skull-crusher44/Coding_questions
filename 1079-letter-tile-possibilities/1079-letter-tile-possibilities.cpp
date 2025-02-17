class Solution {
public:
    void backtrack(unordered_map<string,bool> &mp,vector<bool> &used ,string temp,string &tiles, int n){
        if(mp.find(temp)!=mp.end()){
            return;
        }
            //add temp into map to store it presence
             mp[temp]=true;
            for(int i =0 ; i < n ; i++)
            {  
                if(!used[i]){
                    used[i]=true;
                    backtrack(mp,used,temp+tiles[i],tiles,n);
                    used[i]=false;
                }
            }
        }
    int numTilePossibilities(string tiles) {
        unordered_map<string,bool>mp;
        vector<bool> used(tiles.length(),false);
         backtrack( mp,used,"",tiles,tiles.length());
         return mp.size()-1;
    }
};