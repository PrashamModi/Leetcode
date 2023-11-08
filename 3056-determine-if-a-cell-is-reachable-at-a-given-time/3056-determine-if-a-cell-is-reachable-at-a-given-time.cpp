class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        int dif = max(x , y);
        if(dif > t || (dif == 0 && t == 1)){
            return false;
        }
        return true;
    }
};