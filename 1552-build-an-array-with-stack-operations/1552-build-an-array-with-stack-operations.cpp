class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> s(target.begin(), target.end());
        vector<string> ans;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(cnt == target.size()) break;
            if(s.find(i) != s.end()) {
                ans.push_back("Push");
                cnt++;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};