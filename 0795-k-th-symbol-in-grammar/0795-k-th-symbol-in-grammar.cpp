class Solution {
public:
    string flip(string s) {
        for(auto &it : s) {
            it = it ^ 1;
        }
        return s;
    }
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int length = 1 << (n - 1);
        int mid = length / 2;
        if(k <= mid) {
            return kthGrammar(n - 1, k);
        }
        return !kthGrammar(n - 1, k - mid);
    }
};