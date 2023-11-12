class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int dest) {
        if(src == dest) return 0;

        unordered_map<int, vector<int>> adj;
        for(int i  = 0; i < routes.size(); i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                adj[routes[i][j]].push_back(i);
    
            }
        }

        int ans = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> vis(routes.size(), 0);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front().first;
                int steps = q.front().second;
                q.pop();

                if(node == dest) return steps;
                for(auto it : adj[node]) {
                    if(vis[it]) continue;
                    vis[it] = 1;
                    for(auto itr : routes[it])
                       q.push({itr, steps + 1});
                }
            }
        }
        return -1;
    }
};