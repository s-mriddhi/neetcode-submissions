class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
         while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if (toupper(s[l]) != toupper(s[r])) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
    bool alphaNum(char c){
        return ((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'));

    }
};
