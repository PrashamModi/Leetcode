class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        for(auto it : nums){
            if(m.count(it) != 0){
                ans += m[it];
            }
            m[it]++;
        }
        return ans;
    }
};