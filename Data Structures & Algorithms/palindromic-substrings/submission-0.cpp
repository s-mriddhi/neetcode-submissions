class Solution {
public:
    int countSubstrings(string s) {
        int res =0;
        for(int i =0; i<s.size(); i++){
            res += countPali(s, i, i+1);
            res += countPali(s, i, i);
        }
        return res;
    }
    int countPali(string s, int l, int r){
        int n = s.size();
        int res = 0;
        while(l>=0 && r<n && s[l]==s[r]){
            res++; // this counts also single character
            l--;
            r++;
        }
        return res;
    }
};
