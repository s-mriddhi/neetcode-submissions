class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_res = 0; 
        int n = nums.size();
        for(int i =0; i<=n ; i++){
            xor_res ^= i;
        }
        for(auto num : nums){
            xor_res ^= num;
        }

        return xor_res;
    }
};
