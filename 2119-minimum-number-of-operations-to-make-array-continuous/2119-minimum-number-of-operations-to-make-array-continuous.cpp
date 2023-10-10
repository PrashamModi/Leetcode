class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        set<int> s(nums.begin(), nums.end());
        vector<int> v;
        for(int it : s) {
            v.push_back(it);
        }
        for(int i = 0; i < v.size(); i++) {
            int left = v[i];
            int right = left + n - 1;
            int j = upper_bound(v.begin(), v.end(), right) - v.begin();
            int count = j - i;
            ans = min(ans, n - count);
        }
        return ans;
    }
};