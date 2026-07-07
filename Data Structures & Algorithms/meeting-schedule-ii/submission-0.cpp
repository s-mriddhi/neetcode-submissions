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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector <pair<int, int>> time;
        for(auto i: intervals){
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }
        sort(time.begin(), time.end(),[](auto const &a, auto const &b){
            return a.first==b.first?a.second<b.second:a.first<b.first;
        });

        int res = 0;
        int count = 0;
        for(auto t : time){
            count += t.second;
            res = max(res, count);
        }

        return res;
    }
};
