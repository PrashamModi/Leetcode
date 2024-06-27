class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> flipped(n, false);
        int validFlips = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i >= k) {
                if(flipped[i - k]){
                    validFlips--;
                }
            }

            if(validFlips % 2 == nums[i]) {
                if(n - k < i){
                    return -1;
                }
                validFlips++;
                flipped[i] = true;
                ans++;
            }
        }
        return ans;
    }
};