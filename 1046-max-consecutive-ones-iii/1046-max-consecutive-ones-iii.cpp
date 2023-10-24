class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int currZero = 0;
        while(i < n) {
            currZero += (nums[i] == 0);
            while(currZero > k) {
                currZero -= (nums[j++] == 0);
            }
            ans = max(ans,  i - j + 1);
            i++;
        }
        return ans;
    }
};