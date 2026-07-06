class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s = text1.size();
        int t = text2.size();
        vector<vector<int>> dp(s+1, vector<int> (t+1,0));
        // s X t
        for(int i = 1; i <= s;i++){
            for(int j = 1; j<= t; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[s][t];
    }
};
