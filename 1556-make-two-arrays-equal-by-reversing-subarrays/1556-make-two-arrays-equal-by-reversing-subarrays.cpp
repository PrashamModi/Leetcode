class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> m;
        for(auto it : target) m[it]++;
        for(auto it : arr) {
            if(m.find(it) == m.end()) return false;
            m[it]--;
            if(m[it] == 0)m.erase(it);
        }
        return true;
    }
};