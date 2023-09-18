class Solution {
public:
    int cnt1s (int &m, vector<int> &mat){
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mat[mid] == 1){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            int cnt = cnt1s(m, mat[i]);
            v[i] = {cnt, i};
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = (v[i].second);
        }
        return ans;
    }
};