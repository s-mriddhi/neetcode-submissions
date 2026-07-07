class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> res;
        int n = nums.size();
        for(int i =0; i < (1<<n); i++){
            vector <int> subset;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)){
                    // check if jth bit is set in this ith subset bitmask or not
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }

        return res;
    }
};
