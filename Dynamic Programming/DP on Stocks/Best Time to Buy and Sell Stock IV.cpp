class Solution {
public:

    int maxProfitRecursive(vector<int>& prices, int index, int n, int allowedToBuy, int cap){
        if(index == n){
            return 0;
        }
        if(cap==0) return 0;

        int profit=0;

        if(allowedToBuy == 0){ // i'm allowed to buy a stock.. i.e. selling I cannot do.
            profit = max( -prices[index] + maxProfitRecursive(prices, index+1, n, 1, cap),
                                0        + maxProfitRecursive(prices, index+1, n, 0, cap));
        } 
        if (allowedToBuy == 1) { // I'm not allowed to buy a stock i.e. selling I can do
            profit = max( prices[index]  + maxProfitRecursive(prices, index+1, n, 0, cap-1),
                                0        + maxProfitRecursive(prices, index+1, n, 1, cap));
        }

        return profit;
    }

    int maxProfitRecursiveMemomization(vector<int>& prices, int index, int n, int allowedToBuy, int cap,  vector<vector<vector<int>>> &dp){
        if(index == n){
            return 0;
        }
        if(cap==0) return 0;


        if(dp[index][allowedToBuy][cap] != -1){
            return dp[index][allowedToBuy][cap];
        }

        if(allowedToBuy == 0){ // i'm allowed to buy a stock.. i.e. selling I cannot do.
            dp[index][allowedToBuy][cap] = max( -prices[index] + maxProfitRecursiveMemomization(prices, index+1, n, 1, cap, dp),
                                0        + maxProfitRecursiveMemomization(prices, index+1, n, 0, cap, dp));
        } 
        if (allowedToBuy == 1) { // I'm not allowed to buy a stock i.e. selling I can do
            dp[index][allowedToBuy][cap] = max( prices[index]  + maxProfitRecursiveMemomization(prices, index+1, n, 0, cap-1, dp),
                                0        + maxProfitRecursiveMemomization(prices, index+1, n, 1, cap, dp));
        }

        return dp[index][allowedToBuy][cap];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int allowedToBuy = 1;
        int index =0;
        // recursive solution 
        // return maxProfitRecursive(prices, index, n, 0, 2);   

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return maxProfitRecursiveMemomization(prices, index, n, 0, k, dp);
    }
};
