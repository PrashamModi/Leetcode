class Solution {
public:
    int f(int i, int j, int aliceTurn, vector<int> &piles, vector<vector<vector<int>>> &dp) {
        if(i >= j) return 0;
        if(dp[i][j][aliceTurn] != -1) return dp[i][j][aliceTurn];
        int aliceScore = 0;
        int BobScore = 0;
        if(aliceTurn) {
            int fl = piles[i] + f(i + 1, j, !aliceTurn, piles, dp);
            int fr = piles[j] + f(i, j - 1, !aliceTurn, piles, dp);
            aliceScore += max(fl, fr);
        } else {
            int fl = piles[i] + f(i + 1, j, !aliceTurn, piles, dp);
            int fr = piles[j] + f(i, j - 1, !aliceTurn, piles, dp);
            BobScore += max(fl, fr);
        }
        return dp[i][j][aliceTurn] = max(aliceScore, BobScore);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        int aliceScore = f(0, n - 1, 1, piles, dp);
        if(aliceScore > sum / 2) return true;
        return false;
    }
};