class Solution {
public:

    int numDistinctRecursive(string s,string t,int n,int m)
    {
        if(n==0 and m==0)
            return 1;
        if(n==0)
            return 0;
        if(m==0)
            return 1;
        
        if(s[n-1]==t[m-1]){
            return numDistinctRecursive(s,t,n-1,m-1)+numDistinctRecursive(s,t,n-1,m);
        } else {
            return numDistinctRecursive(s,t,n-1,m);
        }
    }

    int numDistinctRecursiveMemomization(string s,string t,int n,int m, vector<vector<int>> &dp)
    {
        if(n==0 and m==0)
            return 1;
        if(n==0)
            return 0;
        if(m==0)
            return 1;

        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        if(s[n-1]==t[m-1]){
            return dp[n][m] = numDistinctRecursiveMemomization(s,t,n-1,m-1, dp)+numDistinctRecursiveMemomization(s,t,n-1,m, dp);
        } else {
            return dp[n][m] = numDistinctRecursiveMemomization(s,t,n-1,m, dp);
        }
    }

    int numDistinctTabulation(string s,string t,int n,int m)
    {
        vector<vector<double>> dp(n+1, vector<double>(m+1, -1));
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }

    int numDistinctTabulationSpaceOptimized(string s,string t,int n,int m) {
        vector<vector<double>>dp(n+1,vector<double >(m+1,0));
        
        vector<double>prev(m+1,0),curr(m+1,0);
        int i,j;
    
        prev[0]=curr[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=prev[j-1]+prev[j];
                    
                }
                else
                    curr[j]=prev[j];
            }
            
            prev=curr;
        }

        return prev[m];
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        //return numDistinctRecursive(s,t,n,m);
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	    // return numDistinctRecursiveMemomization(s,t,n,m, dp);

        //return numDistinctTabulation(s,t,n,m);

        return numDistinctTabulationSpaceOptimized(s,t,n,m);
    }
};
