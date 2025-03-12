class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int z = 0, o = 0;
        for(auto it : nums){
            if(it < 0) z++;
            else if(it > 0) o++;
        }
        return max(z, o);
    }
};