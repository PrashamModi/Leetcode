class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0; i < details.size(); i++){
            char fc = details[i][11];
            auto sc = details[i][12];
            if(fc < '6') continue;
            else if(fc == '6' && sc != '0')ans++;
            else if(fc > '6')ans++;
        }
        return ans++;
    }
};