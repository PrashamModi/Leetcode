class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flo, vector<int>& pepo) {
        sort(flo.begin(), flo.end());
        vector<int> pep(pepo.begin(), pepo.end());
        sort(pep.begin(), pep.end());

        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pq; //Min heap
        int i = 0;
        for(auto it : pep) {
            while(i < flo.size() && flo[i][0] <= it) {
                pq.push(flo[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < it) pq.pop();
            m[it] = pq.size();
        }
        vector<int> ans;
        for(auto it : pepo) {
            ans.push_back(m[it]);
        }
        return ans;
    }
};