class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dir[] = {0, -1, 0, 1, 0};
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int nr = i + dir[k];
                    int nc = j + dir[k + 1];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int nodeno = i * n + j;
                        int adjnode = nr * n + nc;
                        ds.unionBySize(nodeno, adjnode);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int k = 0; k < 4; k++){
                    int nr = i + dir[k];
                    int nc = j + dir[k + 1];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        components.insert(ds.findUPar(nr * n + nc));
                    }
                }
                int total = 0;
                for(auto it : components){
                    total += ds.size[it];
                }
                mx = max(mx, total + 1);
            }
        }
        for(int i = 0; i < n * n; i++){
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};