class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector <vector<int>> res;
        int n = intervals.size();
        int i = 0;
        bool inserted = false;
        while(i<n){
            while(i<n && intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
                i++;
            }
            while(i<n && intervals[i][0]<=newInterval[1]){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1]= max(newInterval[1], intervals[i][1]);
                i++;
            }
            res.push_back(newInterval);
            inserted = true;
            while(i<n){
                res.push_back(intervals[i]);
                i++;
            }
        }
        if(!inserted) res.push_back(newInterval);
        return res;
    }
};
