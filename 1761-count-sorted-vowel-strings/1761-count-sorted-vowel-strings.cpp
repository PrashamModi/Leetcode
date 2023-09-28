class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6, vector<int>(n + 1, 0));
        for(int i = 0; i < 5; i++) dp[i][0] = 1;
        for(int ind = 4; ind >= 0; ind--){
            for(int j = 1; j <= n; j++){
                int nt = dp[ind + 1][j];
                int tk = dp[ind][j - 1];
                dp[ind][j] = nt + tk;
            }
        }
        return dp[0][n];
    }
};