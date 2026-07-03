class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i<n+1; i++){
            dp[i] = cost[i-1]+dp[i-1];
            dp[i]= min(dp[i], cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};
