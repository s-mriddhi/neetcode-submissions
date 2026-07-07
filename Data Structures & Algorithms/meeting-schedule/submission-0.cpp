/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // all should be non-overlapping
        sort(intervals.begin(), intervals.end(), [](auto const& a, auto const & b){
            return a.end<b.end;
        });
        int prev_end = intervals[0].end;
        for(int i =1; i<intervals.size(); i++){
            if(prev_end > intervals[i].start) return false;
            prev_end = intervals[i].end;
        }
        return true;
    }
};
