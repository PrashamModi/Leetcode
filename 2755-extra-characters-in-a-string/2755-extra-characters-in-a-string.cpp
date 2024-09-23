class Solution {
public:
    unordered_set<string> st;
    int n;
    int f(int ind, string s, vector<int> &dp){
        if(ind >= s.size()){
            return 0;
        }
        if(dp[ind] != -1)return dp[ind];
        string curr = "";
        int minExtra = n;
        for(int i = ind; i < s.size(); i++){
            curr += s[i];
            int currExtra = (st.find(curr) == st.end()) ? curr.length() : 0;
            int nextExtra = f(i + 1, s, dp);
            int totalExtra = currExtra + nextExtra;
            minExtra = min(minExtra, totalExtra);        
        }   
        return dp[ind] = minExtra;
    }
    int minExtraChar(string s, vector<string>& d) {
        n = s.size();
        vector<int> dp(n + 1 ,-1);
        for(auto it : d){
            st.insert(it);
        }
        return f(0, s, dp);
    }
};