class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       
        int prev1=0;
        int prev2=0;
        for(int i = 2; i<n+1; i++){
            int cur = cost[i-1]+prev1;
            cur= min(cur, cost[i-2]+prev2);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
