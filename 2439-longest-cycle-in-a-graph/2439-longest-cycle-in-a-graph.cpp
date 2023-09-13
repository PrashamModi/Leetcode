class Solution {
public:
    int ans = -1;
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathvis, int dis){
        if(!vis[node]){
            vis[node] = 1;
            pathvis[node] = dis;
            dis++;
            for(auto it : adj[node]){
                dfs(it, adj, vis, pathvis, dis);
            }
        } else if(pathvis[node]){
            ans = max(ans, dis - pathvis[node]);
        }
        pathvis[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> vis(n + 1, 0), pathvis(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathvis, 1);
            }
        }
        return ans;
    }
};