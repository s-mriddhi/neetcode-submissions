class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> d;
        int l =0;
        int r =0;
        int n = nums.size();
        while(r<k){
            while(!d.empty() && nums[d.back()]<=nums[r]){
                d.pop_back();
            }
            d.push_back(r);
            r++;
        }
        r--;
        vector <int> res;
        for(l=0; l+k-1<=n-1 ;l++){
            res.push_back(nums[d.front()]);
            if(r<n-1){
                r++;
            while(!d.empty() && nums[d.back()]<=nums[r]){
                d.pop_back();
            }
            d.push_back(r);
            while(d.front()<r-k+1)
                d.pop_front();
            }
        }

        return res;
    }
};
