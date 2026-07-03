class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen =0; int resIndex = 0;
        for(int i =0; i<s.size(); i++){
            int l = i; int r =i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > resLen){
                        resLen = r-l+1;
                        resIndex = l;
                }
                l--;
                r++;
            }

            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > resLen){
                        resLen = r-l+1;
                        resIndex = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(resIndex , resLen);
    }

};
