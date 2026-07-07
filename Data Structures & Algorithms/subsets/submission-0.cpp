class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> res;
        vector <int> subset;
        dfs(nums, 0, res, subset);
        return res;
    }
    void dfs(vector<int>& nums, int i, vector <vector <int>> &res,  vector <int> &subset){
        if(i==nums.size()){
            res.push_back(subset);
            return;
        }
        // Case 1: you take the ith element
        subset.push_back(nums[i]);
        dfs(nums, i+1, res, subset);

        // Case 2: you do not take the ith element
        subset.pop_back();
        dfs(nums, i+1, res, subset);

        return;
    }
};
