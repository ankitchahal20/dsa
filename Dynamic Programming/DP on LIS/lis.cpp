class Solution {
public:

    int lengthOfLISRecursive(vector<int>& nums, int n, int index, int prevIndex ){
        if(index==n) return 0;

        int len=0;

        len = 0 + lengthOfLISRecursive(nums, n, index+1, prevIndex);

        if(prevIndex == -1 || nums[index] >  nums[prevIndex]){
            len = max(len, 1 + lengthOfLISRecursive(nums, n, index+1, index));
        }

        return len;

    }

    int lengthOfLISRecursiveMemomization(vector<int>& nums, int n, int index, int prevIndex, vector<vector<int>> &dp ){
        if(index==n) return 0;

        int len=0;
        if(dp[index][prevIndex+1] != -1){
            return dp[index][prevIndex+1];
        }

        len = 0 + lengthOfLISRecursiveMemomization(nums, n, index+1, prevIndex, dp);

        if(prevIndex == -1 || nums[index] >  nums[prevIndex]){
            len = max(len, 1 + lengthOfLISRecursiveMemomization(nums, n, index+1, index, dp));
        }

        return dp[index][prevIndex+1]= len;

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // recursive solution
        // return lengthOfLISRecursive(nums, n, 0, -1);

        // recursive memomization solution
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return lengthOfLISRecursiveMemomization(nums, n, 0, -1, dp);
    }
};
