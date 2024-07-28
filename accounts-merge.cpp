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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailtonode;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mailtonode.find(mail)== mailtonode.end()){
                    mailtonode[mail]=i;
                }
                else {
                    ds.unionbysize(i , mailtonode[mail]);
                }
            }
        }

        vector<string> mergedmail[n];
        for(auto it: mailtonode){
            string mail = it.first;
            int node = ds.findUparent(it.second);
            mergedmail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(mergedmail[i].size()==0)continue;
            sort(mergedmail[i].begin() , mergedmail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);

        }

        return ans;
    }
};