class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cursum = 0, count = 0;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            cursum+=nums[i];
            int r = (cursum%k + k)%k;
            if(r==0)count++;
            if(mp.find(r) != mp.end())count+=mp[r];
            mp[r]++;
        }
        return count;
    }
};