class DisjointSet {

    public: 
    vector<int> rank , parent,size;
     DisjointSet(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i]=1;
        }
     }
     int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] =  findUparent(parent[node]);
     }

     void unionbyrank(int u , int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
     }
     void unionbysize(int u , int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

     }
};
class Solution {
private:
    bool isvalid(int x , int y , int n){
        return x>=0 && x<n && y>=0 && y<n ;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n  = grid.size();
        DisjointSet ds(n*n );
        int mx=0;

        for(int row  = 0; row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col]==0)continue;
                int delr[]={-1,0,1,0};
                int delc[] = {0,1,0,-1};
                for(int i=0;i<4;i++){
                    int newr=row+delr[i];
                    int newc=col+delc[i];
                    if(isvalid(newr , newc , n) && grid[newr][newc]==1){
                        int adjnodeno = newr*n + newc;
                        int nodeno = row*n + col;
                        ds.unionbysize(nodeno, adjnodeno);
                    }
                }
            }
        }

        for(int row  = 0; row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col]==1)continue;
                int delr[]={-1,0,1,0};
                int delc[] = {0,1,0,-1};
                set<int>components;
                for(int i=0;i<4;i++){
                    int newr=row+delr[i];
                    int newc=col+delc[i];
                    if(isvalid(newr , newc , n)){
                        if(grid[newr][newc]==1){
                            components.insert(ds.findUparent(newr*n + newc));
                        }
                    }
                }
                int sizeT = 0;
                for(auto it:components){
                    sizeT+=ds.size[it];
                }
                mx = max(mx , sizeT+1);
            }
        }

        for(int cell=0;cell<n*n;cell++){
            mx = max(mx , ds.size[ds.findUparent(cell)]);
        }
        return mx;
    }
};