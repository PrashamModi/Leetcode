class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        int curr = 1;
        int ans = 0;
        while(curr <= n) {
            ans++;
            n -= curr;
            curr++;
        }
        return ans;
    }
};