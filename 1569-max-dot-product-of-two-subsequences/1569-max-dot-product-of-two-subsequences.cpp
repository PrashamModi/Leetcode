class Solution {
public:
    int f(int i, int j, vector<int> &a, vector<int> &b, vector<vector<int>> &dp) {
        if(i == a.size() || j == b.size()) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int take_both = a[i] * b[j] + f(i + 1, j + 1, a, b, dp);
        int take_first = f(i + 1, j, a, b, dp);
        int take_second = f(i, j + 1, a, b,  dp);

        return dp[i][j] = max({take_both, take_first, take_second});
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        int fmin = INT_MAX, smin = INT_MAX;
        int fmax = INT_MIN, smax = INT_MIN;

        for(int it : a) {
            fmax = max(fmax, it);
            fmin = min(fmin, it);
        }

        for(int it : b) {
            smax = max(smax, it);
            smin = min(smin, it);
        }

        if((fmax < 0 && smin > 0) || (fmin > 0 && smax < 0)) {
            return max(fmax * smin, fmin * smax);
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int take_both = a[i] * b[j] + dp[i + 1][j + 1];
                int take_first = dp[i + 1][j];
                int take_second = dp[i][j + 1];

                dp[i][j] = max({take_both, take_first, take_second});
            }
        }

        return dp[0][0];
    }
};