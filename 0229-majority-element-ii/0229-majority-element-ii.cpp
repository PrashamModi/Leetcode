class Solution {
public:
    //Extended Moore Voting Algo
    //1.brute n^2
    //2.better hashmap
    //3.best below
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1;
        int num2 = -1;
        int c1 = 0, c2 = 0;
        for(int el : nums){
            if(el == num1)c1++;
            else if(el == num2)c2++;
            else if(c1 == 0){
                c1 = 1;
                num1 = el;
            }
            else if(c2 == 0){
                c2 = 1;
                num2 = el;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int i : nums){
            if(i == num1)c1++;
            else if(i == num2)c2++;
        }
        vector<int> ans;
        if(c1 > n/3)ans.push_back(num1);
        if(c2 > n/3) ans.push_back(num2);
        return ans;
    }
};