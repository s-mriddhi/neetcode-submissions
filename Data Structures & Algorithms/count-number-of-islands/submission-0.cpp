class Solution {
private:
    bool isValid(int &r, int &c, int &n, int &m){
        bool row = (r>=0)&&(r<n);
        bool col = (c>=0)&&(c<m);
        return row&&col;
    }
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int count = 0;
        for(int i =0; i<n;i++){
            for(int j =0; j<m;j++){
                if(!vis[i][j]&& grid[i][j]=='1'){
                    count++;
                    vis[i][j]=1;
                    bfs(i,j,grid, vis);
                }
            }
        }
        return count;
    }
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis){
        queue <pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({r,c});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int row = top.first;
            int col = top.second;
            for(int i = 0; i<4; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(isValid(nr, nc, n, m)&& !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return;
    }
};
