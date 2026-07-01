class Solution {
public:
    int characterReplacement(string s, int k) {
        //max len of substring possible with atmost k+1 distinct characters.
        int l =0;
        int r = 0;
        vector <int> hash(26,0);
        int n = s.size();
        int len = 0;
        while(r<n){
            hash[s[r]-'A'] += 1;
            int max_f = 0;
            for(int f:hash){
                max_f = max(max_f, f);
            }
            int tot = r-l+1;
            if(tot - max_f-k > 0){
                hash[s[l]-'A'] -= 1;
                l++;
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
