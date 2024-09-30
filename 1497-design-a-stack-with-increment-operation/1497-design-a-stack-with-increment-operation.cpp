class CustomStack {
public:
    vector<int> stack;
    int topIndex;
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        topIndex = -1;
    }
    
    void push(int x) {
        if(topIndex < (int)(stack.size()) - 1) {
            stack[++topIndex] = x;
        }
    }
    
    int pop() {
        if(topIndex >= 0) {
            return stack[topIndex--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int limit = min(k, topIndex + 1);
        for(int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */