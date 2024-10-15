class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.size();
        int i = 0, j = n - 1;
        while(j >= 0 && s[j] == '1') j--;
        if(j < 0) return 0;
        
        while(i <= j){
            if(s[i] == '1') {
                swap(s[i], s[j]);
                ans += (j - i);
                i++;
                while(j >= 0 && s[j] == '1') j--;
            }
            else i++;
        }
        return ans;
    } 
};