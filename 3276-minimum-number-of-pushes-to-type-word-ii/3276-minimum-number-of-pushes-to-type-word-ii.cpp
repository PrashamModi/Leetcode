class Solution {
public:
    int minimumPushes(string word) {
        /*
        a -> 2
        b -> 2
        c -> 2
        d -> 2
        e -> 2
        f -> 2
        g -> 2
        h -> 2
        i -> 6
        */
        vector<int> v(26, 0);
        for(auto it : word) v[it - 'a']++;
        sort(v.begin(), v.end());
        int ans = 0;
        int cntr = 1;
        int temp = 1;
        for(int i = v.size() - 1; i >= 0; i--) {
            ans += (v[i] * cntr);
            temp++;
            if(temp == 9) {
                cntr++;
                temp = 1;
            }
        }
        return ans;
    }
};