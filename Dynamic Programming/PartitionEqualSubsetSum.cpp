bool subsetSumToKRecurrsive(int n, int sum, vector<int> &arr){
    if(sum==0){
        return true;
    }

    if(n==0) return false;

    if(arr[n-1]<=sum){
        return subsetSumToKRecurrsive(n-1, sum, arr) || subsetSumToKRecurrsive(n-1, sum-arr[n-1], arr);
    } else {
        return subsetSumToKRecurrsive(n-1, sum, arr);
    }
}

bool subsetSumToKMemomization(int n, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(sum==0){
        return true;
    }

    if(n==0) return false;

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }

    if(arr[n-1]<=sum){
        dp[n][sum] = subsetSumToKMemomization(n-1, sum, arr, dp) || subsetSumToKMemomization(n-1, sum-arr[n-1], arr, dp);
    } else {
        dp[n][sum] = subsetSumToKMemomization(n-1, sum, arr, dp);
    }

    return dp[n][sum];
}

bool subsetSumToKYTabulation(int n, int sum, vector<int> &arr){
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

    for(int i=0;i<=n;i++){
        dp[i][0]= true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]= false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] ;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
    
}

bool subsetSumToKYSpaceOptimizationTabulation(int n, int sum, vector<int> &arr){
    //vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

    vector<bool> prev(sum+1, false);
    vector<bool> curr(sum+1, false);

    prev[0]= true;
    for(int i=1;i<=sum;i++){
        prev[i] = false;
    }
    
    curr = prev;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            bool include = false;
            bool exclude = false;
            if(arr[i-1]<=j){
                include = prev[j-arr[i-1]]  || prev[j];
            } else {
                exclude = prev[j];
            }
            curr[j] = include || exclude;
        }
        prev = curr;
    }

    return prev[sum];
    
}


bool canPartition(vector<int> &arr, int n)
{
	int arrSum=0;
	for(int i=0;i<n;i++) arrSum = arrSum + arr[i];

	if(arrSum%2) return false;

	int k = arrSum/2;

	//return subsetSumToKRecurrsive(n, k,arr);

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    
    // return subsetSumToKMemomization(n, k, arr, dp);
    // return subsetSumToKYTabulation(n,k,arr);

    return subsetSumToKYSpaceOptimizationTabulation(n,k,arr);
	
}
