class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        priority_queue<pair<int, int>> maxPq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;

        while(i < n) {
            maxPq.push({nums[i], i});
            minPq.push({nums[i], i});

            while(maxPq.top().first - minPq.top().first > limit) {
                j = min(maxPq.top().second, minPq.top().second) + 1;
                while(maxPq.top().second < j) maxPq.pop();
                while(minPq.top().second < j) minPq.pop();
            }

            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};