class Solution {
public:
    string minWindow(string t, string s) {
        int n = s.size();
        int m = t.size();
        if(n>m) return "";
        
        vector <int> count1(128,0);
        vector <int> count2(128,0);
        for(int i =0; i<n; i++){
            count1[s[i]]++;
        }
        int req_matches = 0;
        int N = 0;
        for(int i=0; i<128; i++){
            if(count1[i]>0) N++;
        }
        int l =0;
        int r =0;
        int len =INT_MAX;
        int st = 0;
        while( r < m){
            int curr= t[r];
            count2[curr]++;
            if(count1[curr]>0 && count2[curr]==count1[curr]) req_matches++;
            while(req_matches==N){
                if(len > r-l+1){
                    len = r-l+1;
                    st =l; 
                }
                int ind = t[l];
                count2[ind]--;
                
                if(count1[ind]>0 && count1[ind]==count2[ind]+1) req_matches--;
                l++;
            }
            r++;
        }
        if(len==INT_MAX) return "";
    return t.substr(st, len);
    }
};
