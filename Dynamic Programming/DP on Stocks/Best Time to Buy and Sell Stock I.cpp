class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int maxProfit=0;
        int n=prices.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currProfit=prices[j]-prices[i];
                if(currProfit > maxProfit){
                    maxProfit=currProfit;
                }
            }
        }

        return maxProfit;
        */

        int mini=prices[0];
        int maxProfit=0;

        int n=prices.size();

        for(int i=1;i<n;i++){
            int curProfit=prices[i]-mini;
            if(curProfit>maxProfit){
                maxProfit=curProfit;
            }
            if(mini>prices[i]){
                mini=prices[i];
            }
        }
        return maxProfit;
    }
};
