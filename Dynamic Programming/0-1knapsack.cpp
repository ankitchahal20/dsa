#include <bits/stdc++.h> 

int knapsackHelper(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>> &dp) 
{
	if(n==0 || maxWeight == 0) return 0;

	if(dp[n][maxWeight]!=-1){
		return dp[n][maxWeight];
	}

	if(weight[n-1] <= maxWeight){
		return dp[n][maxWeight] = max(knapsackHelper(weight, value, n-1, maxWeight, dp), value[n-1]+knapsackHelper(weight, value, n-1, maxWeight-weight[n-1], dp));
	} else {
		return dp[n][maxWeight] = knapsackHelper(weight, value, n-1, maxWeight, dp);
	}
}

int solveSpaceOptimization(vector<int> weight, vector<int> value, int n, int maxWeight){
	vector<int> prev(maxWeight+1, 0);
	vector<int> curr(maxWeight+1, 0);
	
	
	
	
	//vector<vector<int>> dp(2, vector<int> (maxWeight+1, 0)) ;
	// base case
	// for(int i =0; i<=n;i++){
	// 	for(int j=0;j<=maxWeight;j++){
	// 		if(i==0 || j==0){
	// 			dp[i%2][j]=0;
	// 		} else if(weight[i-1]<=j){
	// 			dp[i%2][j]= max(dp[(i-1)%2][j], value[i-1]+dp[(i-1)%2][j-weight[i-1]]);
	// 		} else {
	// 			dp[i%2][j]= dp[(i-1)%2][j];
	// 		}
	// 	}
	// }
	// return dp[n%2][maxWeight];
}

// using space optimization 
int solve2(vector<int> &weight, vector<int> &value, int index, int capacity) 
{ 
	// step1: pehle dp vhla array create kro
	// vector<vector<int>> dp(index + 1, vector<int>(capacity + 1, -1));
	
	vector<int>prev(capacity+1,0); 
	vector<int>curr(capacity+1,0);
	// step2: base case analyzed kro 
	// for (int w = 0; w <= capacity; w++) 
	// { 
	// 	if (weight[0] <= w) 
	// 	{ 
	// 		prev[w] = value[0]; 
	// 	} 
	// 	else 
	// 	{ 
	// 		prev[w] = 0; 
	// 	} 
	// }
	// step3: aab aapko yha per vo logic lagana hai jo uper lagaya hai lekin loop k andar 
	// index represents rows, capacity represents columns 
	for (int i = 1; i <= index; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			int include = 0;
			if (weight[i-1] <= j) 
			{ 
				include = value[i-1] + prev[j - weight[i-1]]; 
			} 
			int exclude = 0+ prev[j];
			curr[j] = max(include, exclude); 
		}
		prev=curr; 
	} 
	return prev[capacity]; 
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	vector<vector<int>> dp(n+1, vector<int> (maxWeight+1, -1)) ;
	// return knapsackHelper(weight, value, n, maxWeight, dp);

	// for(int i =0; i<=n;i++){
	// 	for(int j=0;j<=maxWeight;j++){
	// 		if(i==0 || j==0){
	// 			dp[i][j]=0;
	// 		} else if(weight[i-1]<=j){
	// 			dp[i][j]= max(dp[i-1][j], value[i-1]+dp[i-1][j-weight[i-1]]);
	// 		} else {
	// 			dp[i][j]= dp[i-1][j];
	// 		}
	// 	}
	// }
	// return dp[n][maxWeight];

	// space optimization
	//return solveSpaceOptimization(weight, value, n, maxWeight);
	return solve2(weight, value, n, maxWeight);
}
