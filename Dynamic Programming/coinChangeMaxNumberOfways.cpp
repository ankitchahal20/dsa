#include <vector>

long countWaysToMakeChangeRecurrsive(int *denominations, int n, int value){
    if(n == 0 ) return 0;

    if(value == 0) return 1;

    if(denominations[n-1]<=value){
        return countWaysToMakeChangeRecurrsive(denominations, n-1, value) + countWaysToMakeChangeRecurrsive(denominations, n, value-denominations[n-1]);
    } else {
        return countWaysToMakeChangeRecurrsive(denominations, n-1, value);
    }
}

long countWaysToMakeChangeRecurrsiveMemoization(int *denominations, int n, int value, vector<vector<long>> &dp){
    if(n == 0 ) return 0;

    if(value == 0) return 1;

    if(dp[n][value] != -1 ){ 
        return dp[n][value];
    }

    if(denominations[n-1]<=value){
        return dp[n][value] = countWaysToMakeChangeRecurrsiveMemoization(denominations, n-1, value, dp) + countWaysToMakeChangeRecurrsiveMemoization(denominations, n, value-denominations[n-1], dp);
    } else {
        return dp[n][value] = countWaysToMakeChangeRecurrsiveMemoization(denominations, n-1, value, dp);
    }
}

long countWaysToMakeChangeTabulation(int *denominations, int n, int value){
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    
    for(int i=0;i<=value;i++){
        dp[0][i]=0;
    }

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=value;j++){
            if(denominations[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i][j-denominations[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][value];
}

long countWaysToMakeChangeSpaceOptimizationTabulation(int *denominations, int n, int value){
    
    vector<long> prev(value+1, 0);
    vector<long> curr(value+1, 0);
    prev[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=value;j++){
            if(denominations[i-1] <= j){
                curr[j] = prev[j] + curr[j-denominations[i-1]];
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[value];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{   
    // recurrsive solution
    //return countWaysToMakeChangeRecurrsive(denominations, n, value);

    // recurrsive-memoization solution
    // vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    // return countWaysToMakeChangeRecurrsiveMemoization(denominations, n, value, dp);

    // tabulation solution
    // return countWaysToMakeChangeTabulation(denominations, n, value);

    // space optimization tabulation solution
    return countWaysToMakeChangeSpaceOptimizationTabulation(denominations, n, value);
}
