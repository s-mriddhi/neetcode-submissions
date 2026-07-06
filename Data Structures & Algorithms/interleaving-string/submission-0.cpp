class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i = s1.length();
        int j = s2.length();
        int k = s3.length();
        if( i + j != k )return false;
        vector<vector<bool>> dp(i+1, vector<bool> (j+1,false));
        // Base Cases
        dp[i][k-i] = true;
        dp[k-j][j] = true;
        for(int x = i; x >= 0;x--){
            for(int y = j; y >= 0; y--){
                if(x<i && s1[x]==s3[y+x]){
                    dp[x][y] = dp[x+1][y];
                }
                if(y<j && s2[y]==s3[y+x]){
                    dp[x][y] = dp[x][y]||dp[x][y+1];
                }
            }
        }
        return dp[0][0];

        // return f(0,0,0,s1,s2,s3);
    }
    bool f(int i, int j, int k, string s1, string s2, string s3){
        if(k == s3.length()){
            return (i==s1.size())&&(j==s2.size());
        }
        if(i<s1.length() && s1[i]==s3[k]){
            if(f(i+1,j,k+1,s1,s2,s3)) return true;
        }
        if(j<s2.length() && s2[j]==s3[k]){
            if(f(i,j+1,k+1,s1,s2,s3)) return true;
        }
    // k = i + j anytime.
        return false;
    }
};
