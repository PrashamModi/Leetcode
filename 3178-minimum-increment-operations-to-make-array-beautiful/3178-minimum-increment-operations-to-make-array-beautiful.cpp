class Solution {
public:
    long long f(int ind, vector<int> &nums, int k, vector<long long> &dp) {
        if(ind == nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long x = 0, y = 0, z = 0;
        x = max(0, k - nums[ind]) + f(ind + 1, nums, k, dp);
        if(ind + 1 < nums.size()) y = max(0, k - nums[ind + 1]) + f(ind + 2, nums, k, dp);
        if(ind + 2 < nums.size()) z = max(0, k - nums[ind + 2]) + f(ind + 3, nums, k, dp);

        return dp[ind] = min({x, y, z});
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long > dp(nums.size(), -1);
        long long ans = f(0, nums, k, dp);
        return ans;
    }
};