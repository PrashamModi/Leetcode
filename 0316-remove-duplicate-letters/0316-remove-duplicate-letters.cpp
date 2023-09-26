class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        int n = s.size();
        vector<int> v(26, 0);
        for(int i = 0; i < n; i++){
            v[s[i] - 'a'] = i;
        }
        vector<bool> vis(26, false);

        for(int i = 0; i < n; i++){
            int curr = s[i] - 'a';
            if(vis[curr]) continue;

            while(ans.length() > 0 && ans.back() > s[i] && i < v[ans.back() - 'a']){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            vis[curr] = true;
        }
        return ans;
    }
};