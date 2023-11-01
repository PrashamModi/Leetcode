class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int> &vis, set<int> &s) {
        vis[node] = 1;
        if(s.find(node) != s.end()) return 0;
        int cnt = 1;
        for(auto it : adj[node]) {
            if(!vis[it])
                cnt += dfs(it, adj, vis, s);
        }
        return cnt;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        set<int> s(restricted.begin(), restricted.end());
        vector<int> vis(n, 0);
        int ans = dfs(0, adj, vis, s);
        return ans;
    }
};