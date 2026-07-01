class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mp;
        int n = s.size();
        int left = 0;
        int right = 0;
        int len =0;
        while(right < n){
            if(mp.count(s[right])!=0 && mp[s[right]]>=left){
                left = mp[s[right]]+1;
            }
            len = max(len, right - left + 1);
            mp[s[right]] = right;
            right++;
        }
        return len;
    }
};
