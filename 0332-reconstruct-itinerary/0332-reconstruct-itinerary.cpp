class Solution {
public:
    bool dfs(string from, vector<string> &curr_path, vector<string> &ans, unordered_map<string, vector<string>> &m, int n){
        curr_path.push_back(from);
        if(curr_path.size() == n + 1){
            ans = curr_path;
            return true;
        }

        vector<string> &adj = m[from];
        for(int i = 0; i < adj.size(); i++){
            string to = adj[i];
            adj.erase(adj.begin() + i);
            if(dfs(to, curr_path, ans, m, n)){
                return true;
            }
            adj.insert(adj.begin() + i, to);
        }
        curr_path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, vector<string>> m;
        for(auto &it : tickets){
            m[it[0]].push_back(it[1]);
        }

        for(auto &it : m){
            sort(it.second.begin(), it.second.end());
        }

        vector<string> curr_path;
        vector<string> ans;
        dfs("JFK", curr_path, ans, m, n);
        return ans;
    }
};