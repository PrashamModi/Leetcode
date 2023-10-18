class Solution {
public:
    int f(int n, map<int, int> &dp) {
        if(n == 1) return 0;
        if(dp.count(n)) return dp[n];
        return dp[n] = 1 + (n % 2 == 0 ? f(n / 2, dp) : f(3 * n + 1, dp));
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        map<int, int> dp;
        for(int i = lo; i <= hi; i++) {
            v.push_back({f(i, dp), i});
        }
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};