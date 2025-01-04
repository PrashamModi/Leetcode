class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> m;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            m[ch] = {-1, -1};
        }
        int n = s.length();
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(m[ch].first == -1) {
                m[ch].first = i;
            }
            else if(m[ch].first != -1) {
                m[ch].second = i;
            }
        }

        int ans = 0;
        for(auto it : m) {
            int start = it.second.first;
            int end = it.second.second;
            unordered_set<char> st;
            for(int i = start + 1; i < end; i++) {
                st.insert(s[i]);
            }
            ans += st.size();
        }
        return ans;
    }
};