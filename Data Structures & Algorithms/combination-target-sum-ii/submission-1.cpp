class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <int> temp;
        dfs(nums, n-1, target, temp);
        return res;
    }
    
     void dfs(vector<int>& nums, int i, int target, vector <int> &temp){
        if(target==0) {res.push_back(temp); return;}
        // Zero cases not allowed here, also: distinct elements, 0/1 knapsack
        if(i<0)return;
       
        //take
        if(target>=nums[i]){
            temp.push_back(nums[i]);
            dfs(nums,i-1,target-nums[i], temp);
            temp.pop_back();
        }
         // not take
        while(i-1>=0 && nums[i]==nums[i-1]){ i--; }
        dfs(nums, i-1, target, temp);
        return ;
    }
};
