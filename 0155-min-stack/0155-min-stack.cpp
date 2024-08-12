class MinStack {
public:
    vector<int> v;
    map<int,int> mpp;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        mpp[val]++;
    }
    
    void pop() {
        int val = v[v.size()-1];
        v.pop_back();
        mpp[val]--;
        if(mpp[val]==0) mpp.erase(val);
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int mini = 0;
        if(mpp.size()>0){
            for(auto it: mpp){
                mini = it.first;
                break;
            }
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */