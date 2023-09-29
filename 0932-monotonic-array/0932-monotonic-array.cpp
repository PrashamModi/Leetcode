class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        
        bool isIncreasing = true;
        bool isDecreasing = true;

        for(int i = 1; i < n; i++){
            if( nums[i - 1] > nums[i] ) {
                isIncreasing = false;
            }

            else if(nums[i - 1] < nums[i]) {
                isDecreasing = false;
            }

            if(!isIncreasing && !isDecreasing) break;
        }

        return isIncreasing || isDecreasing;
    }
};