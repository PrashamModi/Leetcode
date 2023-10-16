class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for(long long ind = n - 1; ind >= 0; ind--) {
            for(int isEven = 0; isEven <= 1; isEven++) {
                if(isEven) {
                    long long notTake = dp[ind + 1][isEven];
                    long long take = nums[ind] + dp[ind + 1][!isEven];
                    dp[ind][isEven] = max(take,  notTake);
                } else {
                    long long notTake = dp[ind + 1][isEven];
                    long long take = -nums[ind] + dp[ind + 1][!isEven];
                    dp[ind][isEven] = max(take, notTake);
                }
            }
        }
        return dp[0][1];
    }
};