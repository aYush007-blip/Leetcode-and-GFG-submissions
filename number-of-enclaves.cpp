class Solution {
    private : 
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n , vector<int>(m,0));
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 && ncol >=0 && nrow <n && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({nrow , ncol});
                    vis[nrow][ncol]=1;
                }
            }
            
            
        }
            int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==0 && grid[i][j]==1) cnt++;
                }
            }
        return cnt;
        

    }
};