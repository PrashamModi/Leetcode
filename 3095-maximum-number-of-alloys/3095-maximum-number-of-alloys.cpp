class Solution {
public:
    typedef long long ll;

    ll f(ll val, vector<int> &comp, vector<int> &stock, vector<int> &cost){
        ll curr_cost = 0;
        for(int i = 0; i < comp.size(); i++){
            curr_cost += max(1ll * (val * comp[i] - stock[i]), 0ll) * cost[i];
        }
        return curr_cost;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll ans = 0;
        for(auto it : composition){
            ll low = 0, high = 1e10, curr = 0;
            while(low <= high){
                ll mid = low + (high - low) / 2;
                if(f(mid, it, stock, cost) <= budget){
                    curr = mid;
                    low = mid + 1;
                } else{
                    high = mid - 1;
                }
            }
            ans = max(ans, curr);
        }
        return (int)ans;
    }
};