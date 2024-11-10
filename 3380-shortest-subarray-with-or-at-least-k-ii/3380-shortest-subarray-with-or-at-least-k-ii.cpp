class Solution {
public:
    int f(vector<int> &v) {
        int ans = 0;
        int mul = 1;
        for(int i = 0; i < 30; i++) {
            if(v[i] > 0) {
                ans += mul;
            }
            mul *= 2;
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(33, 0);
        int ans = INT_MAX;
        int curr = 0;
        int j = 0;
        int i = 0;
        while(i < n) {
            curr = (curr | nums[i]);
            for(int k = 0; k < 31; k++) {
                if(nums[i] & (1 << k)) v[k]++;
            }
            while(j <= i && curr >= k) {
                ans = min(ans, i - j + 1);
                int temp = nums[j];
                for(int k = 0; k < 31; k++) {
                    if(temp & (1 << k)) v[k]--;
                }
                curr = f(v);
                j++;
            }
            
            i++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
}; //3