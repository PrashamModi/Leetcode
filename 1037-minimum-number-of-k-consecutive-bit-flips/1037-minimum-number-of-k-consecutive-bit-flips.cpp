class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int currFlips = 0, totalFlips = 0;
        for(int i = 0; i < n; i++) {
            if(i >= k && nums[i - k] == 2){
                currFlips--;
            }

            if((currFlips % 2) == nums[i]) {
                if(i + k > n) {
                    return -1;
                }
                nums[i] = 2;
                currFlips++;
                totalFlips++;
            }
        }
        return totalFlips;
    }
};