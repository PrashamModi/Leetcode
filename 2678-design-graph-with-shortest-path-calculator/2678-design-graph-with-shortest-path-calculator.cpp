class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it : edges) {
            adj[it[0]].emplace_back(it[1], it[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
    private:
    int dijkstra(int start, int end) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        dist[start] = 0;

        while(!pq.empty()) {
            int currDis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first, adjWeight = it.second;
                if(dist[adjNode] > currDis + adjWeight) {
                    dist[adjNode] = currDis + adjWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */