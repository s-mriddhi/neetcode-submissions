class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_lastIndex = nums[0];
        int n = nums.size()-1;
        int i =0;
        while(i<=n && i<=max_lastIndex){
            int max_reach = nums[i]+i;
            max_lastIndex = max(max_lastIndex, max_reach);
            if(max_lastIndex>=n) return true;
            i++;
        }
        return (max_lastIndex>=n);
    }
};
