class Solution {
    private:
    int nCr(int n , int r){
        int ans = 1;
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1;i<=numRows;i++){
            vector<int> ds;
            int c = 1;
            for(int j=1;j<=i;j++){
                ds.push_back(nCr(i-1 , j-1));
            }
            ans.push_back(ds);
        }
        return ans;

    }
};