class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>> adj[n];
        vector<long> dist(n , LONG_MAX), ways(n , 0);
        long mod = (long)(1e9+7);

        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        

        priority_queue<pair<long,long>  ,  vector<pair<long,long>> , greater<pair<long,long>>>pq;

        dist[0]=0;
        ways[0]=1;

        pq.push({0 , 0});//node , dist

        while(!pq.empty()){
            long dis = pq.top().first;
            long node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                long adjnode = it.first;
                long edw = it.second;

                if(dis + edw < dist[adjnode]){
                    dist[adjnode] = (dis+edw);
                    pq.push({dis + edw, adjnode});
                    ways[adjnode]=(ways[node] % mod);
                }
                else if(dis+edw == dist[adjnode]){
                    ways[adjnode]= (ways[adjnode] + ways[node])%mod;
                }
            }

        }
        return ways[n-1]%mod;
    }
};