class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s = text1.size();
        int t = text2.size();
        vector<vector<int>> dp(s+1, vector<int> (t+1,0));
        // s X t
        vector <int> prev(t+1,0);
        vector <int> curr(t+1,0);
        for(int i = 1; i <= s;i++){
            for(int j = 1; j<= t; j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[t];
    }
};
