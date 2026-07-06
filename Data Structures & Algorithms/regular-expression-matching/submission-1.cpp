class Solution {
public:
    
    bool isMatch(string s, string p) {
        int i = s.size();
        int j = p.size();
       

        vector<vector<bool>> dp(i+1, vector<bool>(j+1, false));
        dp[0][0] = true;
        for(int p_ind = 1; p_ind <= j; p_ind++){
            if(p[p_ind-1]=='*'){
                dp[0][p_ind] = dp[0][p_ind-2];
            }
        }
        for(int s_ind = 1; s_ind <=i; s_ind++){
            for(int p_ind = 1; p_ind <= j; p_ind++){
                if(s[s_ind-1]==p[p_ind - 1] || p[p_ind-1]=='.'){
                    dp[s_ind][p_ind] = 1 && dp[s_ind-1][p_ind-1];
                }
                else if(p[p_ind-1]=='*'){
                    // match zero characters
                    dp[s_ind][p_ind] = dp[s_ind][p_ind-2];
                    // match one character if possible
                    if(s[s_ind-1]==p[p_ind-2]||p[p_ind-2]=='.')
                        dp[s_ind][p_ind] = dp[s_ind][p_ind] || dp[s_ind-1][p_ind];
                }
                else dp[s_ind][p_ind] = false;
            }
        }
        return dp[i][j];
    }
};
