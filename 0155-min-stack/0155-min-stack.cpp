class MinStack {
public:
    stack<int>s;
    stack<int>p;
    MinStack() {
        
    }
    
    void push(int val) {
        p.push(val);
        if(s.empty())
        s.push(val);
        else
        s.push(min(val,s.top()));
    }
    
    void pop() {
        p.pop();
        s.pop();
    }
    
    int top() {
        return p.top();
    }
    
    int getMin() {
        return s.top();
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