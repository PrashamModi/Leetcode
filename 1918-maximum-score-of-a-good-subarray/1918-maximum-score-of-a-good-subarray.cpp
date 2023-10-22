class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k];
        int i = k, j = k;
        int n = nums.size();
        int currMin = nums[k];
        while(i > 0 || j < n - 1) {
            int left = (i > 0 ? nums[i - 1] : 0);
            int right = (j < n - 1 ? nums[j + 1] : 0);

            if(left < right) {
                j++;
                currMin = min(currMin, nums[j]);
            } else {
                i--;
                currMin = min(currMin, nums[i]);
            }

            ans = max(ans, currMin * (j - i + 1));
        }
        return ans;
    }
};