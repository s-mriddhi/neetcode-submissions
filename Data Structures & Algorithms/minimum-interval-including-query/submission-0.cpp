class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(),[](auto const & a, auto const & b){
            return a[0]<b[0];
        });

        vector <int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        unordered_map<int, int> res;

        auto cmp = [](auto const &a, auto const &b){
            return a[0]>b[0]|| (a[0]==b[0] && a[1]>b[1]); // the true case is pushed deeper down the queue
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> mnHeap(cmp);
        int i = 0;
        for(int q : sortedQueries){
            while(i < intervals.size() && intervals[i][0] <= q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                mnHeap.push({r-l+1, r});
                i++;
            }

            while(!mnHeap.empty() && mnHeap.top()[1]<q){
                mnHeap.pop();
            }

            res[q] = mnHeap.empty()?-1:mnHeap.top()[0];
        }

        vector <int> result(queries.size(), -1);
        for(int j = 0; j<queries.size(); j++){
            result[j] = res[queries[j]];
        }
        return result;
    }
};
