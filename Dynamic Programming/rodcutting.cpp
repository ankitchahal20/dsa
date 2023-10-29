int cutRodRecurrsive(int n, int maxLen, vector<int> &price, vector<int> &length){
	if(n==0 || maxLen ==0) return 0;

	if(length[n-1]<=maxLen){
		return max(cutRodRecurrsive(n-1, maxLen, price, length), price[n-1]+cutRodRecurrsive(n, maxLen - n, price, length));
	} else{
		return cutRodRecurrsive(n-1, maxLen, price, length);
	}
}

int cutRodRecurrsiveMemomization(int n, int maxLen, vector<int> &price, vector<int> &length, vector<vector<int>> &dp){
	if(n==0 || maxLen ==0) return 0;

	if(dp[n][maxLen]!=-1){
		return dp[n][maxLen];
	}

	if(length[n-1]<=maxLen){
		return dp[n][maxLen] = max(cutRodRecurrsiveMemomization(n-1, maxLen, price, length, dp), price[n-1]+cutRodRecurrsiveMemomization(n, maxLen - n, price, length, dp));
	} else{
		return dp[n][maxLen] = cutRodRecurrsiveMemomization(n-1, maxLen, price, length, dp);
	}
}

int cutRodRecurrsiveTabulation(int n, int maxLen, vector<int> &price, vector<int> &length){
	vector<vector<int>> dp(n+1,vector<int>(n+1, -1));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=maxLen;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			} else if(length[i-1]<=j){
				dp[i][j] = max( dp[i-1][j], price[i-1]+dp[i][j-length[i-1]]);
			} else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][maxLen];
}

int cutRodRecurrsiveSpaceOptimizationTabulation(int n, int maxLen, vector<int> &price, vector<int> &length){
	vector<int> curr(n+1,0);
	vector<int> prev(n+1,0);

	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxLen;j++){
			if(length[i-1]<=j){
				curr[j] = max( prev[j], price[i-1]+curr[j-length[i-1]]);
			} else{
				curr[j] = prev[j];
			}
		}
		prev = curr;
	}
	return prev[maxLen];
}


int cutRod(vector<int> &price, int n)
{
	// https://leetcode.com/discuss/interview-question/1271572/rod-cutting-dp
	// Rod Cutting is another term for Unbounded Knapsack
	// Here W becomes N , wt[ ] becoes length[ ] , val[ ] becomes price[ ]
	vector<int> length(n,0);
	for(int i=0;i<n;i++){
		length[i]=i+1;
	}

	// recurrsive solution
	// return cutRodRecurrsive(n, n, price, length);

	// recurrsive-memomization solution
	// vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
	// return cutRodRecurrsiveMemomization(n, n, price, length, dp);

	// tabulation solution
	// return cutRodRecurrsiveTabulation(n, n, price, length);

	// space optimization tabulation solution
	return cutRodRecurrsiveSpaceOptimizationTabulation(n, n, price, length);
}
