class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>freq;
        long long  left=0,right=0,res=0;
        int n= s.length();
        for(int i =0 ; i < s.length() ; i++){
            
            char ch=s[i];
            freq[ch]++;
            while(freq.size()==3)
            {
                res+=n-right;
                if(--freq[s[left]]==0)
                    freq.erase(s[left]);
                left++;
            }
            right++;
        }
        return res;
    }
};