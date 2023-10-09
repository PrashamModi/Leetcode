class Solution {
public:
    int first_pos(vector<int>& nums, int target, int low,int high){
        int result = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                result = mid;
                high = mid - 1;
            }
            else if(nums[mid] >= target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return result;
    }
    int last_pos(vector<int>& nums, int target, int low, int high){
        int result = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                result = mid;
                low = mid + 1;
            }
            else if(nums[mid] >= target){
                high = mid - 1;
            }
            else low =  mid + 1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        vector<int>v(2);
        v[0] = first_pos(nums, target, low, high);
        v[1] = last_pos(nums, target, low, high);
        return v;
    }
};