class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globmax = nums[0], curmax = 0;
        int globmin = nums[0], curmin = 0;
        int total = 0;

        for(int &num : nums){
            curmax = max(curmax + num, num);
            globmax = max(globmax, curmax);
            total = total + num;
            curmin = min(curmin + num, num);
            globmin = min(globmin, curmin);
        }
        if(globmax<0) return globmax;
        return max(globmax, total - globmin);
    }
};