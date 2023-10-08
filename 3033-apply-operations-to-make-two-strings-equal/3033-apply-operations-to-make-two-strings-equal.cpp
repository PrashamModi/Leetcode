
class Solution {
public:
    int f(int i, int j, vector<int> &v, int x, vector<vector<int>> &dp) {
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = min(x, v[i + 1] - v[i]) + f(i + 2, j, v, x, dp);

        int op2 = min(x, v[j] - v[j - 1]) + f(i, j - 2, v, x, dp);

        int op3 = min(x, v[j] - v[i]) + f(i + 1, j - 1, v, x, dp);

        return dp[i][j] = min({op1, op2, op3});
    }
    int minOperations(string s, string t, int x) {


        int n = s.length();
        vector<int> v;

        for(int i = 0; i < n; i++)
           if(s[i] != t[i]) v.push_back(i);

        
        if(v.size() & 1) return -1;
        if(v.size() == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, v.size() - 1, v, x, dp);
    }
};