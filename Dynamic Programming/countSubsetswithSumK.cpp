
long long m = 1e9 + 7;
int subsetSumToKRecurrsive(int n, int sum, vector<int> &arr){
    if(sum==0){
        return 1;
    }

    if(n==0) return 0;

    if(arr[n-1]<=sum){
        return subsetSumToKRecurrsive(n-1, sum, arr) + subsetSumToKRecurrsive(n-1, sum-arr[n-1], arr);
    } else {
        return subsetSumToKRecurrsive(n-1, sum, arr);
    }
}

int subsetSumToKMemomization(int n, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(sum==0){
        return 1;
    }

    if(n==0) return 0;

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }

    if(arr[n-1]<=sum){
        dp[n][sum] = (subsetSumToKMemomization(n-1, sum, arr, dp)%m + subsetSumToKMemomization(n-1, sum-arr[n-1], arr, dp)%m)%m;
    } else {
        dp[n][sum] = subsetSumToKMemomization(n-1, sum, arr, dp)%m;
    }

    return dp[n][sum];
}

int subsetSumToKYTabulation(int n, int sum, vector<int> &arr){
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

    for(int i=0;i<=n;i++){
        dp[i][0]= 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]= 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j]%m + dp[i-1][j-arr[i-1]]%m)%m ;
            } else {
                dp[i][j] = dp[i-1][j]%m;
            }
        }
    }

    return dp[n][sum];
}

int subsetSumToKYSpaceOptimizedTabulation(int n, int sum, vector<int> &arr){
    
    vector<int> curr(sum+1,0);
    vector<int> prev(sum+1,0);

    prev[0] = 1;
    for(int i=1;i<=sum;i++){
        prev[i]=0;
    }
    curr = prev;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            int include=0;
            int exclude=0;
            if(arr[i-1]<=j){
                include = (prev[j]%m + prev[j-arr[i-1]]%m)%m ;
            } else {
                exclude = prev[j]%m;
            }
            curr[j]= (include + exclude) %m;
        }
        prev = curr;
    }

    return prev[sum];
}


int findWays(vector<int>& arr, int k)
{

	//return subsetSumToKRecurrsive(arr.size(), k, arr);
	
	// vector<vector<int>> dp(arr.size()+1, vector<int>(k+1, -1));
    // return subsetSumToKMemomization(arr.size(), k, arr, dp);

    //return subsetSumToKYTabulation(arr.size(),k,arr);

    return subsetSumToKYSpaceOptimizedTabulation(arr.size(),k,arr);

}
