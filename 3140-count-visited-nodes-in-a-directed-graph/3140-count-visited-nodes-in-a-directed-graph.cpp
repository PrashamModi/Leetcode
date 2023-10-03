class Solution {
public:
    int dfs(int node, vector<int> &vis, vector<int> &edges, vector<int> &ans, int &isCycle){
        if(vis[node]){
            isCycle = node;
            return ans[node];
        }
        vis[node] = 1;
        ans[node] = 1 + dfs(edges[node], vis, edges, ans, isCycle);

        if(isCycle == node){
            int i = edges[node];
            while(i != node){
                ans[i] = ans[node];
                i = edges[i];
            }
            isCycle = -1;
        }

        return ans[node];
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n, 0);
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int isCycle = -1;
                dfs(i, vis, edges, ans, isCycle);
            }
        }
        return ans;
    }
    // 1 2 0 0
};