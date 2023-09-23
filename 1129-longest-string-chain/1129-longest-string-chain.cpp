class Solution {
public:
    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }
    bool isPred(string &s, string &t){
        int n = s.length();
        int m = t.length();
        if(n >= m || m - n != 1) return false;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == n;
    }
    int f(int prev, int ind, vector<string> &words, vector<vector<int>> &dp){
        if(ind == words.size()){
            return 0;
        }
        if(dp[prev + 1][ind] != -1){
            return dp[prev + 1][ind];
        }
        int nt = f(prev, ind + 1, words, dp);
        int tk = 0;
        if(prev == -1 || isPred(words[prev], words[ind])){
            tk = 1 + f(ind, ind + 1, words, dp);
        }
        return dp[prev + 1][ind] =  max(tk, nt);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return f(-1, 0, words, dp);
    }
};