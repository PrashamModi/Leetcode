class Solution {
public:
    vector<int> dijkstra(vector<int> adj[], int src, int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // int n = adj.size();
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                if(1 + distance < dis[it]){
                    dis[it] = 1 + distance;
                    pq.push({1 + distance, it});
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int a, int b) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        vector<int> v1(n, 1e9), v2(n, 1e9);
        v1 = dijkstra(adj, a, n);
        v2 = dijkstra(adj, b, n);

        int mini = INT_MAX;
        int ans = -1;

        for(int i = 0; i < n; i++){
            if(v1[i] == 1e9 || v2[i] == 1e9) continue;
            if(mini > max(v1[i], v2[i])){
                mini = max(v1[i], v2[i]);
                ans = i;
            }
        }
        return ans;
    }
};