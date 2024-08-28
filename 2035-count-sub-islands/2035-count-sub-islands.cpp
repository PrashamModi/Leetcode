class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>> &g1, vector<vector<int>> &g2) {
        if(g2[i][j] != g1[i][j]) return false;
        g2[i][j] = 0;
        vector<int> dir = {0, -1, 0, 1, 0};
        bool ans = true;
        for(int k = 0; k < 4; k++){
            int ni = i + dir[k];
            int nj = j + dir[k + 1];
            if(ni >= 0 && ni < g1.size() && nj >= 0 && nj < g1[0].size() && g2[ni][nj] == 1){
                ans = ans & dfs(ni, nj, g1, g2);
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1 && dfs(i, j, grid1, grid2)){
                    ans++;
                }
            }
        }
        return ans;
    }
};