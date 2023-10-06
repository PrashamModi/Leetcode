class Solution {
public:
    int f(int n, vector<int> &dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int prod = 0;
        for(int i = 1; i < n ; i++) {
            int temp = max(i * (n - i), i * f(n - i, dp));
            prod = max(prod, temp);
        }
        return dp[n] = prod;
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};