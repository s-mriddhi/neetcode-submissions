class Solution {
private:
    double dist(int x, int y){
        return sqrt(x*x + y*y);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<double,pair<int,int>> pi;
        priority_queue <pi, vector<pi>, greater<pi>> pq;
        for(auto p: points){
            int x = p[0], y =p[1];
            pq.push({dist(x,y),{x,y}});
        }
        vector <vector<int>> res(k);
        for(int i =0; i<k; i++){
            auto top = pq.top();
            pq.pop();
            int x = top.second.first;
            int y = top.second.second;
          
            res[i]={x,y}; 
        }
        return res;
    }
};
