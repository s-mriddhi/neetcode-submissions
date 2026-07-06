class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int level_end = nums[0];
        int level = 0;
        int i = 1;
        while(i<nums.size()&& level_end < nums.size()-1){
            level++;
            int max_reach = level_end;
            for(int j = i ; j <= level_end ; j++){
                max_reach = max(max_reach, nums[j]+j);
            }
            i = level_end + 1;
            level_end = max_reach;   
        }

        return level + 1;
    }
};
