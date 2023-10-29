int unboundedKnapsackRecurrsive(int n, int w, vector<int> &profit, vector<int> &weight){
    if(n==0 || w<=0) return 0;

    if(weight[n-1]<=w){
        return max(unboundedKnapsackRecurrsive(n-1, w, profit, weight), unboundedKnapsackRecurrsive(n, w-weight[n-1], profit, weight)+profit[n-1]);
    } else {
        return unboundedKnapsackRecurrsive(n-1, w, profit, weight);
    }
}

int unboundedKnapsackMemomization(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(n==0 || w<=0) return 0;

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(weight[n-1]<=w){
        return dp[n][w] = max(unboundedKnapsackMemomization(n-1, w, profit, weight, dp), unboundedKnapsackMemomization(n, w-weight[n-1], profit, weight, dp)+profit[n-1]);
    } else {
        return dp[n][w] = unboundedKnapsackMemomization(n-1, w, profit, weight, dp);
    }
}

int unboundedKnapsackTabulation(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(weight[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], profit[i-1]+dp[i][j-weight[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int unboundedKnapsackSpaceOptimizationTabulation(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1,0);
    vector<int> curr(w+1,0);

    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(weight[i-1] <= j){
                curr[j] = max(prev[j], profit[i-1]+curr[j-weight[i-1]]);
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[w];
}



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // recurrsive solution
    //return unboundedKnapsackRecurrsive(n, w , profit, weight);

    // memomization solution
    // vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    // return unboundedKnapsackMemomization(n,w, profit, weight, dp);

    // tabulation solution
    // return unboundedKnapsackTabulation(n, w, profit, weight);

    // tabulation space optimization solution
    return unboundedKnapsackSpaceOptimizationTabulation(n, w, profit, weight);
}
