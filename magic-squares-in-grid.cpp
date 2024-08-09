class Solution {
    private:
    bool onetonine(vector<vector<int>> mat){
        for(auto it: mat){
            for(auto el:it){
                if(el>9 || el<1) return false;
            }
        }
        return true;
    }
    bool duplicate(vector<vector<int>> mat){
        unordered_set<int> elementSet;

    for (const auto& row : mat) {
        for (int element : row) {
            // If the element is already in the set, we have a duplicate
            if (elementSet.find(element) != elementSet.end()) {
                return true;
            }
            // Otherwise, insert the element into the set
            elementSet.insert(element);
        }
    }

    // If no duplicates are found
    return false;
    }
    bool check(vector<vector<int>> mat){
        int r1s=0,r2s=0,r3s=0,c1s=0,c2s=0,c3s=0,d1s=0,d2s=0;
        for(int i=0;i<3;i++){
            r1s+=mat[0][i];
            r2s+=mat[1][i];
            r3s+=mat[2][i];
            c1s+=mat[i][0];
            c2s+=mat[i][1];
            c3s+=mat[i][2];
        }
        d1s+=mat[0][0] + mat[1][1]+ mat[2][2];
        d2s+= mat[0][2]+ mat[1][1] + mat[2][0];
        if(r1s==r2s && r2s==r3s && r3s==c1s && c1s==c2s && c2s==c3s && c3s==d2s && d2s==d1s) return true;
        else return false;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result;
        int cnt=0;
        if(m*n < 9){
            return 0;
        }
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                vector<vector<int>> subg(3 , vector<int>(3));
                for(int l=0;l<3;l++){
                    for(int k=0;k<3;k++){
                        subg[l][k]=grid[i+l][j+k];
                    }
                }
                if(!duplicate(subg)){
                    if(onetonine(subg)){

                    if(check(subg))cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};