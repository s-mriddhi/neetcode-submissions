class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, int> tracker;
        for(auto num : nums){
            if(tracker.find(num) != tracker.end()) return true;
            tracker[num] = 1;
        }
        return false;
    }
};