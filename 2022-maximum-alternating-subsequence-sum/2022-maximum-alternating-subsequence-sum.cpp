class Solution {
public:
    long long f(int ind, vector<int> &nums, int isEven, vector<vector<long long>> &dp) {
        if(ind >= nums.size()) return 0;

        if(dp[ind][isEven] != -1) return dp[ind][isEven];

        if(isEven) {
            long long notTake = f(ind + 1, nums, isEven, dp);
            long long take = nums[ind] + f(ind + 1, nums, !isEven, dp);
            return dp[ind][isEven] = max(take,  notTake);
        } else {
            long long notTake = f(ind + 1, nums, isEven, dp);
            long long take = -nums[ind] + f(ind + 1, nums, !isEven, dp);
            return dp[ind][isEven] = max(take, notTake);
        }
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, nums, 1, dp);
    }
};