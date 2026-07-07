class Solution {
public:
    bool checkValidString(string s) {
        stack <pair<char, int>> left, star;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c=='(') left.push({c,i});
            else if(c=='*') star.push({c,i});
            else{
                if(!left.empty()) left.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!left.empty() && !star.empty()){
            int left_top = left.top().second;
            int star_top = star.top().second;
            if(star_top<left_top)return false;
            left.pop();
            star.pop();
        }
        if(!left.empty()) return false;

        return true;
    }
};
