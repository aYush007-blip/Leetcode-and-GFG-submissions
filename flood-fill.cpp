class Solution {
    private:
    void dfs(int row, int col ,vector<vector<int>>& image, vector<vector<int>>& ans , int color, int inicolor ){
        int n=image.size();
        int m=image[0].size();
        ans[row][col] = color;
        int delrow[] = {-1, 0 , 1, 0};
        int delcol[] = {0, 1 , 0, -1};

        for(int i=0; i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol] !=color){
                dfs(nrow, ncol , image, ans, color, inicolor);
            }

        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, image , ans, color, inicolor);
        return ans;
    }
};