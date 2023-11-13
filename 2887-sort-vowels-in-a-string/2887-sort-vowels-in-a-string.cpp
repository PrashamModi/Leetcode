class Solution {
public:
    int isVow(char x) { 
        if (x == 'a' || x == 'e' || x == 'i' ||  
            x == 'o' || x == 'u' || x == 'A' ||  
            x == 'E' || x == 'I' || x == 'O' || x == 'U') 
            return 1;
        return 0;
    } 
    string sortVowels(string s) {
        string vow = "";
        string ans = s;

        for(int i = 0; i < (int)s.size(); i++) {
            if(isVow(s[i])) vow.push_back(s[i]);
        }

        if(vow.length() == 0) return ans;
        sort(vow.begin(), vow.end());

        int ptr = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVow(s[i])) {
                ans[i] = vow[ptr++];
            }
        }
        return ans;
    }
};