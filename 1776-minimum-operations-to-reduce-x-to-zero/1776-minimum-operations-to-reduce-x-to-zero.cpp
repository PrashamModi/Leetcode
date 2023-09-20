class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = INT_MIN;
        int curr_sum = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sum -= x;
        while(j < n){
            curr_sum += nums[j];
            while(i <= j && curr_sum > sum){
                curr_sum -= nums[i];
                i++;
            }
            if(curr_sum == sum){
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans == INT_MIN ? -1 : n - ans;
    }
};