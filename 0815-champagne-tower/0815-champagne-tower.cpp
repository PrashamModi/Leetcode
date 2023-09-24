class Solution {
public:
    // double f(int poured, int i, int j, vector<vector<double>> &dp){
    //     if(i < 0 || j < 0 || i < j){
    //         return 0.0;
    //     }

    //     if(i == 0 && j == 0){
    //         return poured;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
        
    //     double ul = (f(poured, i - 1, j - 1, dp) - 1) / 2.0;
    //     double ur = (f(poured, i - 1, j, dp) - 1) / 2.0;

    //     ul = max(ul, 0.0);
    //     ur = max(ur, 0.0);

    //     return dp[i][j] = ul + ur;
    // }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double> (query_glass + 1, 0));

        dp[0][0] = (double)poured;

        for(int i = 1; i <= query_row; i++){
            for(int j = 0; j <= query_glass; j++){
                double ul = 0.0;
                if(j > 0) ul = (dp[i - 1][j - 1] - 1) / 2.0;
                double ur = (dp[i - 1][j] - 1) / 2.0;

                ul = max(ul, 0.0);
                ur = max(ur, 0.0);

                dp[i][j] = ul + ur;
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};