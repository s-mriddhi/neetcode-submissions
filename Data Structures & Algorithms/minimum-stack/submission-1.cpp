class MinStack {
private: 
    long long mn = INT_MAX;
    stack <long long> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            mn = val; st.push(val);
        }
        else if(val<mn) {
            long long x = 2*(long long)val-mn;
            st.push(x);
            mn = val;
        }
        else{st.push(val);}
    }
    
    void pop() {
        long long val = st.top();
        if(val<mn){
            mn = 2*mn - val;
        }
        st.pop();
        
    }
    
    int top() {
        long long val = st.top();
        if(val<mn){
            return mn;
        }
        return val;
    }
    
    int getMin() {
        return mn;
    }
};
