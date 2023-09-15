class Solution {
public:
    int prims(vector<vector<pair<int, int>>> &adj, int n){
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //{wt, node}
        pq.push({0, 0});
        long long sum = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node] == 1)continue;
            vis[node] = 1;
            sum += dis;

            for(auto it : adj[node]){
                int adjnode = it.second;
                int wt = it.first;
                if(!vis[adjnode]){
                    pq.push({wt, adjnode});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        

        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                int distance = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({distance, j});
                adj[j].push_back({distance, i});
            }
        }

        return prims(adj, n);
    }
};