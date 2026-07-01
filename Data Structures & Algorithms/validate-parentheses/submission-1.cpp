class Solution {
private:
 char match(char c){
    if(c=='}') return '{';
    if(c==']') return '[';
    if(c==')') return '(';
    return '!';
 }
public:
    bool isValid(string str) {
        stack <char> st;
        int n = str.size();
        for(int i=0; i<n;i++){
            char s = str[i];
            if(s=='{'||s=='['||s=='('){
                st.push(s);
            }
            else if(st.empty()||st.top()!=match(s)) return false;
            else st.pop();
        }

        return st.empty();
    }
};
