class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, int par = -1) {
        if(vis[node]) return true;
        vis[node] = true;
        for(auto it : adj[node]) {
            if(it != par) {
                if(dfs(it, adj, vis, node)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> adj[n + 1];
        vector<int> vis(n + 1, 0);

        for(auto &it : edges) {
            fill(vis.begin(), vis.end(), 0);

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            if(dfs(it[0], adj, vis)) return it;
        }
        return { };
    }
};