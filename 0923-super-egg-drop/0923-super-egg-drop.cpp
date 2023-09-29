class Solution {
public:
    int f(int eggs, int floors, vector<vector<int>> &dp) {
        if(eggs == 1 || floors <= 1) {
            return floors;
        }

        if(dp[eggs][floors] != -1) return dp[eggs][floors];

        int ans = 1e7;
        int low = 0, high = floors;

        while(low <= high) {
            int mid = low + (high - low)/2;
            int left = f(eggs - 1, mid - 1, dp);
            int right = f(eggs, floors - mid, dp);

            int worstCase = 1 + max(left, right);

            if(left < right){
                low = mid + 1;
            } else{
                high = mid - 1;
            }

            ans = min(ans, worstCase);
        }
        return dp[eggs][floors] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return f(k, n, dp);
    }
};