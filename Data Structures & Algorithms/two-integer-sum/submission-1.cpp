class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       unordered_map <int, int> numMap;
        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            // Check if the complement already exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store the current number and its index
            numMap[numbers[i]] = i;
        }
        
        return {};
    }
};
