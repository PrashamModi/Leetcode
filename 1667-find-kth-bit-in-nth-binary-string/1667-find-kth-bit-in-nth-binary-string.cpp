class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 0; i < n - 1; i++) {
            string temp = s;
            s.push_back('1');
            for(int j = s.length() - 2; j >= 0; j--){
                s.push_back(!(s[j] - '0') + '0');
            }
        }
        return s[k - 1];
    }
};