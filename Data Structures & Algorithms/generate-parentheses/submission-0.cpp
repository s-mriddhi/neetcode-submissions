class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        string stackk;
        // open , close
        backtrack(0,0, n, res, stackk);
        return res;
    }
    void backtrack(int openN, int closedN, int n, vector <string> &res, string& stackk){
        if(openN==closedN && openN==n){
            res.push_back(stackk);
            return;
        }
        if(openN < n){
            stackk += '(';
            backtrack(openN + 1, closedN, n, res, stackk);
            stackk.pop_back();
        }
        if(closedN < openN){
            stackk += ')';
            backtrack(openN, closedN + 1, n, res, stackk);
            stackk.pop_back();
        }
    }
};

