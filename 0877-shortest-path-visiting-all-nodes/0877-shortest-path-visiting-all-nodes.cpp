class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
         if(n == 1 || n == 0)
            return 0;
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;

        int allVisitedMask = (1 << n) - 1;
        for(int i = 0; i < n; i++){
            int maskValue = (1 << i);
            q.push({i, maskValue});
            vis.insert({i, maskValue});
        }

        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                int currNode = q.front().first;
                int currMask = q.front().second;
                q.pop();

                for(auto &it : graph[currNode]){
                    int nextMask = (currMask | (1 << it));
                    if(nextMask == allVisitedMask) return ans;

                    if(vis.find({it, nextMask}) == vis.end()){
                        vis.insert({it, nextMask});
                        q.push({it, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};