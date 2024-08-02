// class Solution {
//     private:
//     bool dfs(int node , int c , vector<vector<int>> graph , int color[]){
//         color[node]=c;
//         for(auto it: graph[node]){
//             if(color[it]==-1 ){
//                 if(dfs(it , !c , graph , color)==false) return false;
//             }
//             else if(color[it]==c){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n =  graph.size();
//         int color[n];
//         for(int i=0;i<n;i++)color[i]=-1;
//         int c = 0;
//         for(int i=0;i<n;i++){
//             if(color[i]==-1 && !dfs(i,!c , graph , color)){
//                 if(dfs( 0 , c , graph , color)==false) return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    vector<int> p;

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (int u = 0; u < n; ++u) {
            auto& g = graph[u];
            for (int v : g) {
                if (find(u) == find(v)) return 0;
                p[find(v)] = find(g[0]);
            }
        }
        return 1;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};