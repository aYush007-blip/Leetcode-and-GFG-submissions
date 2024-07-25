class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


        int delrow[] = {-1 ,-1 , 0 , 1 , 1 , 1 , 0 , -1};
        int delcol[] = {0 , 1, 1, 1 , 0 , -1 , -1,  -1};
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>> dist(n , vector<int>(n , 1e9));
        dist[0][0]=0;  
        queue<pair<int , pair<int,int>>>pq; 

        pq.push({0 , {0,0}});

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int distance = it.first;

            for(int i=0;i<8;i++){
                
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                    
                if( nrow>=0 && ncol >=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 && dist[nrow][ncol] > distance +1 ){
                dist[nrow][ncol]=distance+1;
                    if(nrow==n-1 && ncol==n-1){
                        return distance+2;
                    }
                pq.push({1+distance, {nrow , ncol}});
                }
                
            }
        }
    return -1;  
    }
};