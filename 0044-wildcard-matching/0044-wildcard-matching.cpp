class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        // dp[i][j] = whether first i chars of s match first j chars of p
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Fill first row: when s is empty, pattern must be all '*'
        for(int j = 1; j <= m; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the rest of the table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    // characters match or ? wildcard
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*') {
                    // * matches zero characters (dp[i][j-1]) OR one char (dp[i-1][j])
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
