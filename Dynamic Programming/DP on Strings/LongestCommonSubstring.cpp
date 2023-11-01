int lcsRecursive(string s, int m, string t, int n, int count){
    if(m==0 || n==0){
        return count;
    }

    if(s[m-1] == t[n-1]){
        count = lcsRecursive(s, m-1, t, n-1, count+1);
    }
    // else part is not there.
    count = max(count, max(lcsRecursive(s, m, t, n-1,0), lcsRecursive(s, m-1, t, n, 0)));
    
    return count;
}

int lcsRecursiveMemomization(string s, int m, string t, int n, int count, vector<vector<vector<int>>> &dp){
    if(m==0 || n==0){
        return count;
    }
     int cForT3d = count;

    if(dp[m][n][count] != -1){
        return dp[m][n][count];
    }

    if(s[m-1] == t[n-1]){
        count = lcsRecursiveMemomization(s, m-1, t, n-1, count+1, dp);
    }
    // else part is not there.
    count = max(count, max(lcsRecursiveMemomization(s, m, t, n-1, 0, dp), lcsRecursiveMemomization(s, m-1, t, n, 0, dp)));
    return dp[m][n][cForT3d] = count;
}

int lcsTabulation(string s, int m, string t, int n){
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxi=-1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi=max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

int lcsTabulationSpaceOptimization(string s, int m, string t, int n){
    
    vector<int> prev(n+1,0);
    vector<int> curr(n+1,0);
    int maxi=-1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                curr[j] = 1 + prev[j-1];
                maxi=max(maxi, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return maxi;
}


int lcs(string &str1, string &str2){
    int m=str1.size();
    int n=str2.size();
    int count=0;
    
    /*
        recursive solution 
        int ans = lcsRecursive(str1, m, str2, n, count);
        return ans;
    */

    /* recursive memomization solution
        The reason why we require 3-D array is because a total of 3 variables are changing in each recurrsive call.
   
    
    int c=min(m,n); 
    vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(c+1,-1)));

    int ans = lcsRecursiveMemomization(str1, m, str2, n, count, dp);
    return ans;
    */


    // lcs Tabulation
    //return lcsTabulation(str1, m, str2, n);

    // lcs Tabulation Space Optimization
    return lcsTabulationSpaceOptimization(str1, m, str2, n);

}
