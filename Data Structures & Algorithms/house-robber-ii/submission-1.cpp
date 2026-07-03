class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector <int> h1(nums.size()-1,0);
        vector <int> h2(nums.size()-1,0);
        for(int i =0; i<nums.size(); i++){
            if(i>0) h2.push_back(nums[i]);
            if(i<n-1) h1.push_back(nums[i]);
        }
        return max(f(h1), f(h2));
    }

    int f(vector <int> &nums){
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

