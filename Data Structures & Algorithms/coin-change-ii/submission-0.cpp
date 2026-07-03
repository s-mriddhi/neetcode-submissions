class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector <vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0; i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i] = 1;
            }
        }
         for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1; j<amount+1;j++){
                int take = 0;
                if(j>=coins[i]){
                        take = dp[i][j - coins[i]];    
                }
                int ntake = dp[i-1][j];
                dp[i][j] = take + ntake;
            }
        }
        return dp[n-1][amount];
    }
};
