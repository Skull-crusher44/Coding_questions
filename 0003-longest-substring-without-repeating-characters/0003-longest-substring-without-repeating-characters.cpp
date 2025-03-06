class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        int max_len=0;
        vector<int>mp(256,-1);
        for(int i =0 ; i < n ; i++)
        {
            if(mp[s[i]]!=-1 )  // if we find duplicate then update left pointer 
            left=max(mp[s[i]]+1,left);
            mp[s[i]]=i;         //update right pointer 
            max_len=max(i-left+1,max_len);
        }
        return max_len;
    }
};