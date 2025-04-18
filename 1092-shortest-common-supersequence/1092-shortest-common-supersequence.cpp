class Solution {
public:
    void reverse(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++,j--;
        }
    }
    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        // Create a 2D array to store lengths of common subsequence at each index.
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      
        // Loop through both strings and fill the dp array.
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // If current characters match, add 1 to the length of the sequence
                // until the previous character from both strings.
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If current characters do not match, take the maximum length
                    // achieved by either skipping the current character of text1 or text2.
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int i=n,j=m;
        string ans="";
        while(i>0&&j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        reverse(ans);
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string longest_string = longestCommonSubsequence(str1,str2);
        int n = str1.length();
        int m = str2.length();

        int i=0,j=0,k=0;
        string ans="";
        for(char c : longest_string){
            while(i<n && str1[i]!=c){
                ans+=str1[i++];
            }
            while(j<m && str2[j]!=c){
                ans+=str2[j++];
            }
            ans+=c;
            i++;
            j++;
        }
        // Append the remaining parts of str1 and str2
        while (i < n) 
        ans += str1[i++];
        while (j < m) 
        ans += str2[j++];
        return ans;
    }
};