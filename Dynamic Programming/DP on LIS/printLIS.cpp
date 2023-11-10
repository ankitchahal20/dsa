vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n, 1);
	vector<int> hash(n, 1);
	int maxLen = 1;
	int lastIndex = 1;
	for(int i=0;i<n;i++){
		hash[i]=i;
		for(int prev=0;prev<i;prev++){
			if(arr[prev] < arr[i] && 1+dp[prev]>dp[i]){
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
			}
		}
		if(dp[i]>maxLen){
			maxLen = dp[i];
			lastIndex = i;
		}
	}

	vector<int> res;
	res.push_back(arr[lastIndex]);

	while(lastIndex != hash[lastIndex]){
		lastIndex = hash[lastIndex];
		res.push_back(arr[lastIndex]);
	}
	reverse(res.begin(), res.end());
	return res;
}
