class Solution {
public:
    // int orangesRotting(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     queue<pair<pair<int, int>, int>> q;

    //     int vis[n][m];
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]==2){
    //                 q.push({{i,j},0});
    //                 vis[i][j]=2;
    //             }
    //             else vis[i][j]=0;
    //         }
    //     }

    //     int tm=0;
    //     int drow[]={-1,0,1,0};
    //     int dcol[]={0,1,0,-1};

    //     while(!q.empty()){
    //         int r = q.front().first.first;
    //         int c = q.front().first.second;
    //         int t = q.front().second;
    //         tm = max(tm,t);
    //         q.pop();
    //         for(int i=0;i<4;i++){
    //             int neighrow = r+drow[i];
    //             int neighcol = c+dcol[i];
    //             if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && vis[neighrow][neighcol]!=2 && grid[neighrow][neighcol]==1){
    //                 q.push({{neighrow,neighcol}, t+1});
    //                 vis[neighrow][neighcol]=1;
    //             }
    //         }
    //     }

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(vis[i][j]!=2 && grid[i][j]==1) return -1;
    //         }
    //     }


    //     return tm;
    // }
    int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
};