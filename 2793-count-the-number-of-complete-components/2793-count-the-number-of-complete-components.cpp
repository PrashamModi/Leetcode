class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &cnt){
        vis[node] = 1;
        cnt.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, cnt);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> cnt;
                dfs(i, adj, vis, cnt);
                bool flag = true;
                for(int j = 0; j < cnt.size(); j++){
                    if(adj[cnt[j]].size() != cnt.size() - 1){
                        flag = false;
                        break;
                    }
                }
                if(flag)ans++;
            }
        }
        return ans;
    }
};