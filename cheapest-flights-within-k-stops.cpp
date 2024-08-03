class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> >  pq;

        //stop , {node , cost}
        vector<int> dist(n , 1e9);
        dist[src]=0;
        pq.push({0 , { src , 0}});

        while(!pq.empty()){
            auto it = pq.top();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            pq.pop();
            if(stop>k) continue;
            for(auto it: adj[node]){
                int adjnode = it.first;
                int adjcost = it.second;
                if(dist[adjnode] > cost + adjcost && stop<=k ){
                    dist[adjnode] = cost+ adjcost;
                    pq.push({stop+1 , {adjnode , cost+adjcost}});
                }
            }

        }
        if(dist[dst]!=1e9) return dist[dst];
        else return -1;
    }
};