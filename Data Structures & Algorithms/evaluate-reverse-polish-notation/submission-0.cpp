class Solution {
private:
    bool isOperator(string s){
        return s=="+"||s=="*"||s=="-"||s=="/";
    }
    int calc(int i, int j, string c){
        if(c=="+") return i+j;
        if(c=="-")return i-j;
        if(c=="*") return i*j;
        if(c=="/") return i/j;
        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto c : tokens){
            if(!isOperator(c)){
                st.push(stoi(c));
            }
            else{
                int op2= st.top(); st.pop();
                int op1 = st.top(); st.pop();
                st.push(calc(op1,op2,c));
            }
        }
        return st.top();
    }
};
