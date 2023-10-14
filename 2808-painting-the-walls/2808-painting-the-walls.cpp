class Solution {
public:
    int f(int ind, vector<int>&cost, vector<int> &time, int wallsRem, vector<vector<int>> &dp) {

        if(wallsRem <= 0) return 0;
        if(ind >= cost.size()) return 1e9;

        if(dp[ind][wallsRem] != -1) return dp[ind][wallsRem];

        int notTake = f(ind + 1, cost, time, wallsRem, dp);
        int take = cost[ind] + f(ind + 1, cost, time, wallsRem - time[ind] - 1, dp);
        return dp[ind][wallsRem] = min(take, notTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, cost, time, n, dp);
    }
};