class Solution {
public:
    int numTeams(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int leftSmall = 0, rightSmall = 0;
            int leftLarge = 0, rightLarge = 0;

            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]){
                    leftSmall++;
                } else if (nums[i] < nums[j]) {
                    leftLarge++;
                }
            }

            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]){
                    rightLarge++;
                } else if (nums[i] > nums[j]) {
                    rightSmall++;
                }
            }

            ans += leftSmall * rightLarge + leftLarge * rightSmall;
        }

        return ans;
    }
};