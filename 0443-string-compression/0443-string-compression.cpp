class Solution {
public:
    int compress(vector<char>& chars) {
        string str = "";

        for(int i = 0; i < chars.size(); i++) {
            int cnt = 1, ind = i;
            
            while(i < chars.size() - 1) {
                if(chars[i] == chars[i + 1]) {
                    cnt++;
                    i++;
                } else break;
            }
            
            str += chars[ind];
            if(cnt > 1) str += to_string(cnt);
        }

        chars.clear();
        for(int i = 0; i < str.size(); i++) {
            chars.push_back(str[i]);
        }
        return chars.size();
    }
};