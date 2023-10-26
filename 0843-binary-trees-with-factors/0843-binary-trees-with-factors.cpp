class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> m;
        m[arr[0]] = 1;

        for(int i = 1; i < n; i++) {
            int root = arr[i];
            m[root] = 1;

            for(int j = 0; j < i; j++) {
                int left = arr[j];
                if(root % left == 0 && m.find(root / left) != m.end()) {
                    m[root] += m[left] * m[root / left];
                }
            }
        }
        long long ans = 0;
        for(auto it : m) {
            ans = (ans + it.second) % mod;
        }
        return ans % mod;
    }
};