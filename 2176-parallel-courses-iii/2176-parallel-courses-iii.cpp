class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1, 0);
        for(auto it : relations) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }


        queue<int> q;
        vector<int> ans (n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(!indegree[i]) {
                q.push(i);
                ans[i] = time[i - 1];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                ans[it] = max(ans[it], time[it - 1] + ans[node]);
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};