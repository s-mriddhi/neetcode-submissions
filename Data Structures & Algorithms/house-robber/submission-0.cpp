class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = max(nums[0], dp[0]);
        for(int i=2; i<=n; i++){
            // take
            dp[i] = nums[i-1] + dp[i-2];
            // ntake
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n];
    }
};
