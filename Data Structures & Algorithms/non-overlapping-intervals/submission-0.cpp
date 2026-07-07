class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // We need maximum non overlapping intervals
        // Sort by shorstest ending time first
        sort(intervals.begin(), intervals.end(), [](auto const & a, auto const & b){
            return a[1]<b[1];
        });
        int n = intervals.size();
        int count = 1;
        int end_time = intervals[0][1];
        for(int i =1; i<n; i++){
            if(intervals[i][0]>=end_time){
                end_time = intervals[i][1];
                count++;
            }
        }

        return n - count;
    }
};
