class Solution {
public:

    int minDistanceRecursive(string word1, int m, string word2, int n){
        if(m==0 || n==0){
            return max(m,n);
        }
        if(word1[m-1]==word2[n-1]){
            return minDistanceRecursive(word1, m-1, word2, n-1);
        }

        int a = 1 + minDistanceRecursive(word1, m-1, word2, n);
        int b = 1 + minDistanceRecursive(word1, m,   word2, n-1);
        int c = 1 + minDistanceRecursive(word1, m-1, word2, n-1);

        return min(a,min(b,c));
    }

    int minDistanceRecursiveMemoization(string word1, int m, string word2, int n, vector<vector<int>> &dp){
        if(m==0 || n==0){
            return max(m,n);
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        if(word1[m-1]==word2[n-1]){
            return dp[m][n] = minDistanceRecursiveMemoization(word1, m-1, word2, n-1, dp);
        }

        int a = 1 + minDistanceRecursiveMemoization(word1, m-1, word2, n, dp);
        int b = 1 + minDistanceRecursiveMemoization(word1, m,   word2, n-1, dp);
        int c = 1 + minDistanceRecursiveMemoization(word1, m-1, word2, n-1, dp);

        return dp[m][n] = min(a,min(b,c));
    }

    int minDistanceTabulation(string word1, int m, string word2, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i =0;i<=n;i++){
            dp[0][i]=i;
        }

        for(int i =0;i<=m;i++){
            dp[i][0]=i;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int a = 1+dp[i-1][j];
                    int b = 1+dp[i][j-1];
                    int c = 1+dp[i-1][j-1];
                    dp[i][j] = min(c, min(a,b));
                }
            }
        }
        
        return dp[m][n];
    }

    int minDistanceTabulationSpaceOptimization(string word1, int m, string word2, int n) {
        
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        for(int i =0;i<=n;i++){
            prev[i]=i;
        }
        
        for(int i=1;i<=m;i++){
            curr[0] = i;
            for(int j=1;j<=n;j++){
                if( word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                } else {
                    int a = 1+prev[j];
                    int b = 1+curr[j-1];
                    int c = 1+prev[j-1];
                    curr[j] = min(c, min(a,b));
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }

    int minDistance(string word1, string word2) {
        
        int m=word1.size();
        int n=word2.size();

        // Recursive
        //return minDistanceHelper(word1, m, word2, n);

        // Recursive Memoization
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return minDistanceRecursiveMemoization(word1, m, word2, n, dp);

        // Tabulation
        // return minDistanceTabulation(word1, m, word2, n);

        // Tabulation Space Optimization
        return minDistanceTabulationSpaceOptimization(word1, m, word2, n);
    }
};
