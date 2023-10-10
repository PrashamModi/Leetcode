class Solution {
public:
    int ans = 0;
    void f(int ind, vector<int> &v, int n) {
        if(ind > n) {
            ans++;
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!v[i] && ((ind % i == 0) || (i % ind == 0))) {
                v[i] = 1;
                f(ind + 1, v, n);
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n + 1, 0);
        f(1, v, n);
        return ans;
    }
    
};