class Solution {
public:
    int lis(vector<int> &v) {
        vector<int> temp;
        temp.push_back(v[0]);
        for(int i = 1; i < v.size(); i++) {
            if(v[i] >= temp.back()) {
                temp.push_back(v[i]);
            } else {
                int idx = upper_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
                temp[idx] = v[i];
            }
        }
        return temp.size();
    }
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> v;
        for(auto it : s) {
            if(it == 'a') v.push_back(0);
            else v.push_back(1);
        }
        return n - lis(v);
    }
};