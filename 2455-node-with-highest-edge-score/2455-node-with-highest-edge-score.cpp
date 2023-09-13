class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> cnt(n, 0);
        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                cnt[edges[i]] += i;
            }
        }
        long long ans = -1;
        long long maxi = -1;
        for(int i = 0; i < n; i++){
            if(cnt[i] > maxi){
                maxi = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};