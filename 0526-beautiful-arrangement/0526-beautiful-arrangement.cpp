class Solution {
public:
    int ans = 0;
    void permutations(int nums[], int ind, int n) {
        if(ind == n) {
            ans++;
            return;
        }
        for(int i = ind; i < n; i++) {
            swap(nums[i], nums[ind]);
            if(nums[ind] % (ind + 1) == 0 || (ind + 1) % nums[ind] == 0){
                permutations(nums, ind + 1, n);
            }
            
            swap(nums[i], nums[ind]);
        }
    }
    int countArrangement(int n) {
        int arr[n] ;
        for(int i = 1; i <= n; i++){
            arr[i - 1] = i;
        }
        permutations(arr, 0, n);
        return ans;
    }
    
};