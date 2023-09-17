class Solution {
public:
    int countPairs(vector<vector<int>>& coor, int k) {
        int n = coor.size();
        int ans = 0;
        map<pair<int, int>, int> m;

        for(auto it : coor){
            int x1 = it[0];
            int y1 = it[1];
            for(int i = 0; i <= k; i++){
                int x2 = x1 ^ i;
                int y2 = y1 ^ (k - i);
                ans += m[{x2, y2}];
            }
            m[{x1, y1}]++;
        }
        return ans;
    }
};