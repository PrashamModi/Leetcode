class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> s;
        s.insert(1);
        long ans = 1;
        for(int i = 0; i < n; i++){
            ans = *(s.begin());
            s.erase(ans);
            s.insert(2 * ans);
            s.insert(3 * ans);
            s.insert(5 * ans);
        }
        return ans;
    }
};