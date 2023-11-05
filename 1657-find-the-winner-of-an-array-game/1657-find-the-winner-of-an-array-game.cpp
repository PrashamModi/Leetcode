class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = arr[0];
        
        for(int i = 1; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }

        int curr = arr[0];
        int len = 0;

        for(int i = 1; arr.size(); i++){
            int next = arr[i];
            if(curr > next) {
                len++;
            }else{
                curr = next;
                len = 1;
            }
            if(len == k || curr == maxi) return curr;
        }
        return -1;
    }
};