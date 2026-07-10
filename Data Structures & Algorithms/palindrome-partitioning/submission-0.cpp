class Solution {
public:
    vector <vector<string>> res;
    vector<vector<string>> partition(string s) {
        int j = s.size();
        vector <vector<bool>> dp(j+2, vector <bool> (j+2, true));
        for(int i = 1; i<=j;i++){
            dp[i][i] = true;
        }
        for(int i =j; i>0; i--){
            for(int x = 1; x<=j; x++){
                if(x<i) continue;
                if(s[i-1]==s[x-1]) dp[i][x] = dp[i+1][x-1];
                else dp[i][x] = false;
            }
        }
    // 1 based index check
        vector <string> temp;
        dfs(1,s,temp, dp);
        return res;
    }

    void dfs(int i, string &s, vector <string> &temp, vector <vector<bool>> &dp){
        int n = s.size();
        if(i>n) {res.push_back(temp);return;}

        for(int k = i; k<=n;k++){
            if(dp[i][k]){
                temp.push_back(s.substr(i-1, k-i+1));
                dfs(k+1, s, temp, dp);
                temp.pop_back();
            }
        }
        return;
    }
};
