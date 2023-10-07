class Solution {
public:
    int numTeams(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(nums[j] < nums[i]){
                    dp[i]++;
                    ans += dp[j]; 
                }
            }
        }

        fill(dp.begin(), dp.end(), 0);

        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(nums[j] > nums[i]){
                    dp[i]++;
                    ans += dp[j]; 
                }
            }
        }

        return ans;
    }
};