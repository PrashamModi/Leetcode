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
    int integerBreak(int N) {
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int n = 2; n <= N; n++) {
            int prod = 0;
            for(int i = 1; i < n ; i++) {
                int temp = max(i * (n - i), i * dp[n - i]);
                prod = max(prod, temp);
            }
            dp[n] = prod;
        }
        return dp[N];
    }
};