class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = (n + 1) / 2;
        int ans = n;
        while(i < n / 2 && j < n){
            if(nums[i++] < nums[j++]) ans -= 2;
        }
        return ans;
    }
};

