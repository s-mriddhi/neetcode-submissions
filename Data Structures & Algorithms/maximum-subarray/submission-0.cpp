class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum= nums[0], curSum = 0;
        for(auto num : nums){
            if(curSum<0){
                curSum = 0;
            }
            curSum += num;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
