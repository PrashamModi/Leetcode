class Solution {
public:
    int f(vector<int>& arr, int k){
        int n = arr.size();
        vector<int> prev(k + 1, 0);
        
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;
        for(int ind = 1; ind < n; ind++){
            vector<int> curr(k + 1, 0);
            for(int target = 0; target <= k; target++ ){
                int notpick = prev[target];
                int pick = 0;
                if(arr[ind] <= target)
                    pick = prev[target - arr[ind]];
                curr[target] = (pick + notpick);
            }
            prev = curr;
        }
        return prev[k];
    
    }
    int findTargetSumWays(vector<int>& arr, int d) {
        int totsum = 0;
        for(int i = 0; i < arr.size(); i++) {
            totsum += arr[i];
        }
        if(totsum - d < 0) return 0;
        if((totsum - d) % 2 == 1) return 0;
        int s2 = (totsum - d)/2;
        return f(arr, s2);
    }
};