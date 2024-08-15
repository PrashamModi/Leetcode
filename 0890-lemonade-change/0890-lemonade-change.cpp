class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntF = 0, cntT = 0;
        for(auto it : bills) {
            if(it == 5) cntF++;
            else if(it == 10) {
                if(cntF == 0) return false;
                cntF--;
                cntT++;
            }
            else {
                if(!cntF){
                    return false;
                }
                cntF--;
                if(cntT) cntT--;
                else if(cntF >= 2) cntF-=2;
                else return false;
            }
        }
        return true;
    }
};