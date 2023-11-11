class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevSmaller(n, -1), prevGreater(n, -1), nextSmaller(n, n), nextGreater(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) prevSmaller[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(!st.empty()) nextSmaller[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) prevGreater[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) nextGreater[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long leftMin = i - prevSmaller[i], rightMin = nextSmaller[i] - i;
            long long leftMax = i - prevGreater[i], rightMax = nextGreater[i] - i;

            ans += (leftMax * rightMax - leftMin * rightMin) * nums[i];
        }

        return ans;
    }
};