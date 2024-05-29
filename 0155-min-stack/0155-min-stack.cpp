//solution 1 using another stack
// class MinStack {
// public:
//     stack<int>s;    // it will store min elemnets
//     stack<int>p;  // it will store history of min elements
//     MinStack() {
        
//     }
    
//     void push(int val) {    //s=> 2 5 8 1 4 5
//         p.push(val);        //p=> 2 2 2 1 1 1(min elements in stack s)
//         if(s.empty())
//         s.push(val);
//         else
//         s.push(min(val,s.top()));
//     }
    
//     void pop() {
//         p.pop();
//         s.pop();
//     }
    
//     int top() {
//         return p.top();
//     }
    
//     int getMin() {
//         return s.top();
//     }
// };

//solution 2=> Here we putting element then minimum element from stack 
class MinStack {
public:
stack<int>s;
int minEle;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!s.empty())
           minEle=min(s.top(),val);
           else
           minEle=val;
           
           s.push(val);           
           s.push(minEle);
    }
    
    void pop() {
           s.pop();
           s.pop();
         
    }
    
    int top() {
        int top_min=s.top();
        s.pop();
        int top=s.top();
        s.push(top_min);
        return top;
        
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