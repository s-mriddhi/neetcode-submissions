class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> temp;
        dfs(nums, n-1, target, temp);
        return res;
    }

    void dfs(vector<int>& nums, int i, int target, vector <int> &temp){
        if(target==0) {res.push_back(temp); return;}
        // Zero cases not allowed here, also: distinct elements
        if(i<0)return;
        // not take
        dfs(nums, i-1, target, temp);
        //take
        if(target>=nums[i]){
            temp.push_back(nums[i]);
            dfs(nums,i,target-nums[i], temp);
            temp.pop_back();
        }
        return ;
    }
};
