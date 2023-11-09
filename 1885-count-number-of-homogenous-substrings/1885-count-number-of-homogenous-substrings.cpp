class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        long long int ans = 0;
        int i = 0;
        int n = s.size();
        while(i < n){
            long long cnt = 0;
            char prev = s[i];
            while(i < n && (s[i] == prev)){
                i++;
                cnt++;
            }
            long long temp = (long long)(cnt * (cnt + 1)) % mod;
            ans += (temp / 2);
        }
        return ans;
    }
};