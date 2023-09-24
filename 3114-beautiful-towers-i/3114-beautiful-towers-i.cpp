class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        long long ans = 0;
        for(int i = 0; i < h.size(); i++){
            long long sum = h[i], last = h[i];

            for(int j = i - 1; j >= 0; j--){
                last = min((long long)h[j], last);
                sum += last;
            }

            last = h[i];

            for(int j = i + 1; j < h.size(); j++){
                last = min((long long)h[j], last);
                sum += last;
            }

            ans = max(ans, sum);
        }
        return ans;
    }
};