int longestPalindromeSubseqRecursive(string &s, string &t, int m, int n){
        if(m==0 || n==0){
            return 0;
        }
        
        if(s[m-1]==t[n-1]){
            return 1 + longestPalindromeSubseqRecursive(s, t, m-1, n-1);
        }
            
        return max(longestPalindromeSubseqRecursive(s,t,m-1,n),longestPalindromeSubseqRecursive(s,t,m,n-1));
}

int longestPalindromeSubseqRecursiveMemoization(string &s, string &t, int m, int n, vector<vector<int>> &dp){
        if(m==0 || n==0){
            return 0;
        }

        if(dp[m][n] !=-1){
            return dp[m][n];
        }
        
        if(s[m-1]==t[n-1]){
            return dp[m][n] = 1 + longestPalindromeSubseqRecursiveMemoization(s, t, m-1, n-1, dp);
        }
            
        return dp[m][n] = max(longestPalindromeSubseqRecursiveMemoization(s, t, m-1, n, dp),longestPalindromeSubseqRecursiveMemoization(s, t, m, n-1, dp));
    }

    int longestPalindromeSubseqTabulation(string &s, string &t, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                } else if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }

    int longestPalindromeSubseqSpaceOptimizedTabulation(string &s, string &t, int m, int n){
        
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = 1 + prev[j-1]; 
                } else {
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    


int minimumInsertions(string &s)
{
	string t = s;
	reverse(s.begin(), s.end()); 
    int m=s.size();
    int n=t.size();
	
	// recursive solution
	// return s.size() - longestPalindromeSubseqRecursive(s, t, m, n);

    // recursive memoization
    // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    // return s.size() - longestPalindromeSubseqRecursiveMemoization(s, t, m, n, dp);

    // tabulation solution
    // return s.size() - longestPalindromeSubseqTabulation(s, t, m, n);

    // tabulation space optimized solution
    return s.size() - longestPalindromeSubseqSpaceOptimizedTabulation(s, t, m, n);
}
