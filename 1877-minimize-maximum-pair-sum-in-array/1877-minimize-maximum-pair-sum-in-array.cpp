class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = INT_MIN;
        int i = 0, j = nums.size() - 1;
        while(i < j){
            mini = max(mini, nums[i++] + nums[j--]);
        }
        return mini;
    }
};