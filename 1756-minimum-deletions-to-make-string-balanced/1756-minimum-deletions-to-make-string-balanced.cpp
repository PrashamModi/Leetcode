class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int pref[n];
        int suff[n];
        pref[0] = 0;
        suff[n - 1] = 0;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (s[i - 1] == 'b');
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + (s[i + 1] == 'a');
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++) {
            ans = min(ans, pref[i] + suff[i]);
        }
        return ans;
    }
};