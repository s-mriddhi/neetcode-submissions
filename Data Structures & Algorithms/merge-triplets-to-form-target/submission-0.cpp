class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int max0=0, max1= 0, max2 = 0;
        for(auto triplet : triplets){
            if(triplet[0]>target[0] || triplet[1]>target[1] || triplet[2]>target[2])
                continue;
            max0 = max(max0, triplet[0]);
            max1 = max(max1, triplet[1]);
            max2 = max(max2, triplet[2]);
        }
        vector <int> result = {max0, max1, max2};
        return result == target;
    }
};
