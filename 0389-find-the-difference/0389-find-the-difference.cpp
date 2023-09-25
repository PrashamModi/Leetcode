class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a']++;
        }
        for(int j = 0; j < t.size(); j++){
            v[t[j] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(v[i] % 2 == 1){
                char ans = i + 'a';
                return ans;
            }
        }
        return '123';

        
    }
};