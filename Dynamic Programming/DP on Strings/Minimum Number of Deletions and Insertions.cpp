int lcsRecursive(string s, string t, int m, int n)
{
	if(m==0 || n==0){
		return 0;
	}

	if(s[m-1] == t[n-1]){
		return 1 + lcsRecursive(s, t, m-1, n-1);
	}

	return max(lcsRecursive(s, t, m-1, n), lcsRecursive(s, t, m, n-1));
}

int lcsRecursiveMemoization(string s, string t, int m, int n, vector<vector<int>> &dp)
{
	if(m==0 || n==0) {
		return 0;
	}

	if(dp[m][n] != -1){
		return dp[m][n];
	}

	if(s[m-1] == t[n-1]){
		return dp[m][n] = 1 + lcsRecursiveMemoization(s, t, m-1, n-1, dp);
	}

	return dp[m][n] = max(lcsRecursiveMemoization(s, t, m-1, n, dp), lcsRecursiveMemoization(s, t, m, n-1, dp));
}

int lcsTabulation(string s, string t, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				dp[i][j] = 0 ;
			} else if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	return dp[m][n];
}

int lcsTabulationSpaceOptimization(string s, string t, int m, int n)
{
	
	vector<int> prev(n+1, 0);
	vector<int> curr(n+1, 0);
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1] == t[j-1]){
				curr[j] = 1 + prev[j-1];
			} else {
				curr[j] = max(curr[j-1], prev[j]);
			}
		}
		prev = curr;
	}
	return prev[n];
}

int canYouMake(string &s1, string &s2){
    int m = s1.size();
    int n = s2.size();

    // recursive solution
    // return  m + n - 2* lcsRecursive(s1, s2, m, n);

    // recursive memomization
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // return  m + n - 2* lcsRecursiveMemoization(s1, s2, m, n, dp);

    // LCS Tabulation
	// return m + n - 2*lcsTabulation(s1, s2, m, n);

	// LCS Tabulation Space Optimization
	return m + n - 2*lcsTabulationSpaceOptimization(s1, s2, m, n);
}
