class DisjointSet {
    vector<int> rank , parent,size;

    public: 
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol , it[1]);
        }
        DisjointSet ds(maxrow + maxcol+2);
        unordered_map<int,int> stonenodes;
        for(auto it: stones){
            int nodeR = it[0];
            int nodeC = it[1]+ maxrow +1;
            ds.unionbysize(nodeR , nodeC);
            stonenodes[nodeR]=1;
            stonenodes[nodeC]=1;
        }

        int cnt=0;
        for(auto it: stonenodes){
            if(ds.findUparent(it.first) == it.first){
                cnt++;
            }
        }
         return stones.size()-cnt;

    }
};