class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> hash(nums.begin(), nums.end());
        int longest = 0;
        for(int num : hash){
            if(hash.find(num-1)==hash.end()){
                int length = 1;
                while(hash.find(num + length)!=hash.end()){
                    length++;
                }
                longest = max(length, longest);
            }
        }
    return longest;
    }
};
