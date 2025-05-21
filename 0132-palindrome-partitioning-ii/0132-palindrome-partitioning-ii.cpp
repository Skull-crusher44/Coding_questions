class Solution {
public:
    vector<vector<int>>dp;
	vector<vector<int>> dp1;

	bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		return dp1[i][j] = false;
	    return true;
    } 

    int solve(string s, int i, int j) {
        if (i >= j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
        if(isPalindrome(s,i,k)){
            int temp = solve(s, i, k) +
                        solve(s, k + 1, j) +
                        1;
            ans = min(ans, temp);
            }

            
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        dp1.resize(s.size(),vector<int> (s.size(),-1));  
        return solve(s, 0, n - 1);
    }
};