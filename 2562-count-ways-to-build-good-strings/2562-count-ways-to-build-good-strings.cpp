class Solution {
public:
    int mod = 1e9 + 7;
    int f(int cnt, int zero, int one, vector<int>&dp){
        if(cnt == 0) return 1;
        if(cnt < 0) return 0;
        if(dp[cnt] != -1) return dp[cnt];
        long long sum = f(cnt - zero, zero, one, dp) + f(cnt - one, zero, one, dp);
        return dp[cnt] = (sum % mod);
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for(int i = low; i <= high; i++){
            ans = ((ans % mod) + f(i, zero, one, dp)) % mod;
        }
        return ans;
    }
};