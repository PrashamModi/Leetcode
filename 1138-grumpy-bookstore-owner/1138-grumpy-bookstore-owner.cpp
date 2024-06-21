class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& gmp, int mins) {
        int n = gmp.size();
        int windowMax = 0;
        for(int i = 0; i < mins; i++) {
            if(gmp[i]) windowMax += nums[i];
        }

        int extra = windowMax;
        for(int i = mins; i < n; i++) {
            if(gmp[i]) windowMax += nums[i];
            if(gmp[i - mins]) windowMax -= nums[i - mins];
            extra = max(extra, windowMax);
        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            if(!gmp[i]) total += nums[i];
        }
        return total + extra;
    }
};