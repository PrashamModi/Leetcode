class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = arr[0];
        queue<int> q;
        for(int i = 1; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            q.push(arr[i]);
        }

        int curr = arr[0];
        int len = 0;

        while(!q.empty()) {
            int next = q.front();
            q.pop();

            if(curr > next) {
                q.push(next);
                len++;
            }else{
                q.push(curr);
                curr = next;
                len = 1;
            }

            if(len == k || curr == maxi) return curr;
        }
        return -1;
    }
};