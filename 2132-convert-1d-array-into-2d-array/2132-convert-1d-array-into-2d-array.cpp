class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>v(m, vector<int>(n));
        if(m * n != original.size()) return {};
        int i = 0, j = 0;
        for(int k = 0; k < original.size(); k++) {
            v[i][j] = original[k];
            j++;
            if(j == n) {
                j = 0;
                i++;
            }
        }
        return v;
    }
};