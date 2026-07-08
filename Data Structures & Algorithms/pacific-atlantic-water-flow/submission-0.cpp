class Solution {

public:
    vector<int> drow= {-1, 0, 1, 0};
    vector <int> dcol = {0, 1, 0, -1};
    bool isValid(int r, int c, int n, int m ){
        bool row = (r>=0)&&(r<n);
        bool col = (c>=0)&&(c<m);
        return row && col;
    }
    vector<vector<int>> res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // we will reverse the condition, that is we will start from edges neighbouring both pacific and atlantic ocean alright, it will flow to next cell if it has height equal or greater than current.
        // we will keep two visited matrix fro pacific water and atlantic water each
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> p_vis(m, vector<bool>(n,false)), a_vis(m, vector<bool>(n,false));
        // bfs on pacific adjacent
        for(int i =0; i<n; i++){
            if(p_vis[0][i] != true)
           {
             p_vis[0][i] = true;
            bfs(0,i,true,p_vis,a_vis,heights);
           }
        }
        for(int i =1; i<m; i++){
            if(p_vis[i][0] != true){
                 p_vis[i][0] = true;
                bfs(i,0,true,p_vis,a_vis,heights);
            }
        }

        //bfs on atlantic adjacent
        for(int i = 0; i < m; i++){
            if(a_vis[i][n-1] != true){
                a_vis[i][n-1] = true;
                bfs(i,n-1,false,p_vis,a_vis,heights);
            }  
        }
        for(int i = 0; i<n-1 ; i++){
            if(a_vis[m-1][i] != true){
                a_vis[m-1][i] = true;
                bfs(m-1,i,false,p_vis,a_vis,heights);
            } 
        }
        for(int i = 0; i < m;i++){
            for(int j = 0; j<n; j++){
                if(a_vis[i][j]&&p_vis[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }

    void bfs(int r, int c, bool flag, vector<vector<bool>> &p_vis,vector<vector<bool>> &a_vis,
    vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();
        queue <pair<int, int>> q;
        q.push({r,c});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int row = top.first;
            int col = top.second;
            for(int i = 0; i<4; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(isValid(nr,nc,m,n)&&((flag==true&&!p_vis[nr][nc])||flag==false&&!a_vis[nr][nc])&& heights[row][col]<=heights[nr][nc]){
                    if(flag){
                        p_vis[nr][nc] = true;
                        q.push({nr,nc});
                    }
                    else{
                        a_vis[nr][nc] = true;
                         q.push({nr,nc});
                    }
                }
            }
        }
    }
};