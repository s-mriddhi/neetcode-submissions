class Solution {
private:
    bool isValid(int & r, int &c, int& m, int &n){
        bool row = (r>=0)&&(r<m);
        bool col = (c>=0)&&(c<n);
        return row&&col;
    }

    vector<int> drow={-1, 0, 1, 0};
    vector <int> dcol = {0, 1, 0, -1};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue <pair<int, pair<int, int>>> q;
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int dist = top.first;
            int row = top.second.first;
            int col = top.second.second;
            for(int i = 0; i<4 ; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(isValid(nr,nc,m,n)&&grid[nr][nc]==INT_MAX){
                    grid[nr][nc] = dist + 1;
                    q.push({dist + 1,{nr,nc}});
                }
            }
        }
    }
};
