class MinStack {
public:
    stack<int> st;
    stack<int> minor;
    MinStack() {
        
    }
    // created two stacks st for value and minor or having smallest value at top()
    void push(int val) {
        st.push(val);
        if(minor.empty()){
            minor.push(val);
        }else{
            if(minor.top() < val){
                minor.push(minor.top());
            }else{
                minor.push(val);
            }
        }
    }
    
    void pop() {
        st.pop();
        minor.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minor.top();
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
