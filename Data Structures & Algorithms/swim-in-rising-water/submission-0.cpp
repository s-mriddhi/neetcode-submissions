class Solution {
public:
    vector <int> drow = {-1, 0, 1, 0};
    vector <int> dcol = {0, 1, 0, -1};
    bool isValid(int r, int c, int m , int n){
        bool row = (r>=0)&&(r<m);
        bool col = (c>=0)&&(c<n);
        return row&&col;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        typedef pair<int, pair<int, int>> pi;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({grid[0][0], {0,0}});
       vector<vector<bool>> visited(m, vector<bool>(n, false));
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int time = top.first;
            int r = top.second.first;
            int c = top.second.second;
            if(visited[r][c]) continue;
            visited[r][c] = true;
            if((r==m-1)&&(c==n-1)) return time;
            for(int i =0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(isValid(nr,nc,m,n) && !visited[nr][nc]){
                    int req = grid[nr][nc];
                    pq.push({max(time,req),{nr,nc}});
                }
            }
        }
        return -1;
    }
};
