class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <vector<int>> dp(n,vector<int>(amount+1,INT_MAX));
        for(int i=0; i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i] = i/coins[0];
            }
        }
         for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        for(int i=1;i<n;i++){
            for(int j=1; j<amount+1;j++){
                int take = INT_MAX;
                if(j>=coins[i]){
                    if(dp[i][j-coins[i]]!=INT_MAX){
                        take = 1 + dp[i][j - coins[i]];
                    }
                }
                int ntake = dp[i-1][j];
                dp[i][j] = min(take,ntake);
            }
        }
        return dp[n-1][amount]==INT_MAX?-1:dp[n-1][amount];
    }
    int f(int i, int amount, vector<int>& coins){
        if(amount==0) return 0;
        if(i<0||i>=coins.size()) return INT_MAX;
        int take = INT_MAX;
        if(amount>=coins[i]){
            int result = f(i, amount-coins[i], coins);
            if(result!=INT_MAX){
                take = 1+result;
            }
        }
        int notTake = f(i+1,amount, coins);

        return min(take,notTake);
    }
};
