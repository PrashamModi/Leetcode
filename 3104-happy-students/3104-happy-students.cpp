class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        if(nums[0] != 0) ans++;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i < n - 1 && (i + 1) > nums[i] && (i + 1) < nums[i + 1]) ans++;
            else if(i == n - 1 && (i + 1) > nums[i]) ans++;
        }
        return ans;
    }
};