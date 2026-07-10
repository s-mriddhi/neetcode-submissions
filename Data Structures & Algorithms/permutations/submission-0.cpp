class Solution {
    vector <vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <bool> pick(nums.size(), false);
        vector <int> perm;
        backtrack(perm, pick, nums);
        return res;
    }
    void backtrack(vector <int> &perm, vector <bool> &pick, vector<int>& nums){
        if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
        }
        for(int i = 0; i < pick.size(); i++){
            if(!pick[i]){
                pick[i] = true;
                perm.push_back(nums[i]);
                backtrack(perm, pick, nums);
                perm.pop_back();
                pick[i]=false; // Backtrack, so that furthur index elements can choose previous indexes
            }
        }
        return;
    }
};
