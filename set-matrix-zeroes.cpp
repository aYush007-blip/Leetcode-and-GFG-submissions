class Solution {
    private:
    void setzero(vector<int> rows , vector<int> cols ,vector<vector<int>>& matrix , int m , int n ){
        for(auto it: rows){
            for(int j=0;j<n;j++){
                matrix[it][j]=0;
            }
        }
        for(auto it: cols){
            for(int j=0;j<m;j++){
                matrix[j][it]=0;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows , cols;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        setzero(rows , cols , matrix , m , n);


        
    }
};