class Solution {
public:
    char findTheDifference(string s, string t) {

        int sum = 0;
        for(auto it : t)sum += it;
        for(auto it : s)sum -= it;
        return (char)(sum);

        // char ans = '\0';
        // for(auto it : s) ans ^= it;
        // for(auto it : t) ans ^= it;
        // return ans;


        // vector<int> v(26, 0);
        // for(int i = 0; i < s.size(); i++){
        //     v[s[i] - 'a']++;
        // }
        // for(int j = 0; j < t.size(); j++){
        //     v[t[j] - 'a']++;
        // }
        // for(int i = 0; i < 26; i++){
        //     if(v[i] % 2 == 1){
        //         char ans = i + 'a';
        //         return ans;
        //     }
        // }
        // return '123';
    }
};