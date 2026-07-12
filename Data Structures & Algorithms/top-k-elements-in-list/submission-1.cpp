class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }
        vector <vector<int>> count(n+1);
        for(auto const& [element, frequency]:freq){
            count[frequency].push_back(element);
        }
        vector<int> res;
        for(int i = n; i>= 0; i--){
            for(int num : count[i]){
                if(res.size()==k){
                    break;
                }
                res.push_back(num);
                
            }
        }
        return res;
    }
};
