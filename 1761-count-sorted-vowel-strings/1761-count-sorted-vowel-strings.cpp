class Solution {
public:
    int f(int ind, int n, vector<vector<int>> &dp){
        if(n == 0) return 1;
        if(ind >= 5) return 0;

        if(dp[ind][n] != -1) return dp[ind][n];

        int nt = f(ind + 1, n, dp);
        int tk = f(ind, n - 1, dp);
        return dp[ind][n] = nt + tk;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6, vector<int>(n + 1, -1));
        return f(0, n, dp);
    }
};