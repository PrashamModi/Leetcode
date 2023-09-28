class Solution {
public:
    int f(int ind, vector<int> &arr, int k, vector<int> &dp){
        if(ind == arr.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j = ind; j < min(ind + k, (int)arr.size()); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = maxi * len + f(j + 1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] =  maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k, dp);
    }
};