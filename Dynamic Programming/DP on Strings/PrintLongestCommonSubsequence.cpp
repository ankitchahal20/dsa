string lcsTabulation(string s, string t, int m, int n)
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
	int len=dp[m][n];

	string str="";
	for(int i=0;i<len;i++){
		str=str+'#';
	}
	
	int index=len-1;
	int i = m, j= n;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			str[index]=s[i-1];
			index--;
			i--;
			j--;
		} else if(dp[i][j-1]>dp[i-1][j]){
			j--;
		} else {
			i--;
		}
	}
	return str;
	
}
string findLCS(int n, int m,string &s1, string &s2){
	return lcsTabulation(s1, s2, n, m);
}
