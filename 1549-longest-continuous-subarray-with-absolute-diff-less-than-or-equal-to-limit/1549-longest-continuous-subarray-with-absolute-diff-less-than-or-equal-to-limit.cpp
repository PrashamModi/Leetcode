class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        multiset<int> ms;

        while(i < n) {
            ms.insert(nums[i]);

            while(*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[j]));
                j++;
            }

            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};