class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;

        for (int j = 1; j <= m; ++j)
            dp[0][j] = j;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(
                       min( 1 + dp[i][j - 1],    // instead insertion of char in s remove from t and as reason of insertion is to match with character of t  
                            1 + dp[i - 1][j]  // deletion match target[0...j] with remaining substr of s after removing last char (i)
                          ),
                        1 + dp[i-1][j-1]  // Replacement both index will be moved as s[i-1] will change to t[j-1]
                        );
            }
        }

        return dp[n][m];
    }
};