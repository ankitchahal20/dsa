#include <bits/stdc++.h>

string shortestCommonSuperSequenceTabulation(string s, string t, int m, int n)
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
	int len = dp[m][n];
  	int i = m;
  	int j = n;

  	int index = len - 1;
  	string ans = "";

  	while (i > 0 && j > 0) {
    	if (s[i - 1] == t[j - 1]) {
      		ans += s[i-1];
      		index--;
      		i--;
      		j--;
    	} else if (dp[i - 1][j] > dp[i][j - 1]) {
        	ans += s[i-1];
        	i--;
    	} else {
        	ans += t[j-1];
        	j--;
    	}
  	}
  
  	//Adding Remaing Characters - Only one of the below two while loops will run 
  
  	while(i>0){
    	ans += s[i-1];
      	i--;
  	}
  	while(j>0){
    	ans += t[j-1];
      	j--;
  	}

  	reverse(ans.begin(),ans.end());
  
  	return ans;
	
}

string shortestSupersequence(string a, string b)
{
	int m=a.size();
	int n=b.size();
	return shortestCommonSuperSequenceTabulation(a, b, m, n);
}
