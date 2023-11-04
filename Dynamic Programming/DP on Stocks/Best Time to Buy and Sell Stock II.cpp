class Solution {
public:

    int maxProfitRecursive(vector<int>& prices, int index, int n, int allowedToBuy){
        if(index == n){
            return 0;
        }

        int profit=0;

        if(allowedToBuy == 0){ // i'm allowed to buy a stock.. i.e. selling I cannot do.
            profit = max( -prices[index] + maxProfitRecursive(prices, index+1, n, 1),
                                0        + maxProfitRecursive(prices, index+1, n, 0));
        } 
        if (allowedToBuy == 1) { // I'm not allowed to buy a stock i.e. selling I can do
            profit = max( prices[index]  + maxProfitRecursive(prices, index+1, n, 0),
                                0        + maxProfitRecursive(prices, index+1, n, 1));
        }

        return profit;
    }

    int maxProfitRecursiveMemomization(vector<int>& prices, int index, int n, int allowedToBuy, vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }


        if(dp[index][allowedToBuy] != -1){
            return dp[index][allowedToBuy];
        }

        if(allowedToBuy == 0){ // i'm allowed to buy a stock.. i.e. selling I cannot do.
            dp[index][allowedToBuy] = max( -prices[index] + maxProfitRecursiveMemomization(prices, index+1, n, 1, dp),
                                0        + maxProfitRecursiveMemomization(prices, index+1, n, 0, dp));
        } 
        if (allowedToBuy == 1) { // I'm not allowed to buy a stock i.e. selling I can do
            dp[index][allowedToBuy] = max( prices[index]  + maxProfitRecursiveMemomization(prices, index+1, n, 0, dp),
                                0        + maxProfitRecursiveMemomization(prices, index+1, n, 1, dp));
        }

        return dp[index][allowedToBuy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int allowedToBuy = 1;
        int index =0;
        // recursive solution 
        // return maxProfitRecursive(prices, index, n, 0);

        // recursive memomization solution
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfitRecursiveMemomization(prices, index, n, 0, dp);
    }
};
