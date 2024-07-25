class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1 , 1e9);

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

        pq.push({k , 0});
        dist[k]=0;
        while(!pq.empty()){
            auto itr = pq.top();
            int node = itr.first;
            int time = itr.second;
            pq.pop();

            for(auto it: adj[node]){
                
                int adjnode = it.first;
                int adjtime = it.second;

                if(dist[adjnode] > dist[node]+ adjtime){
                    dist[adjnode] = dist[node]+ adjtime;
                    pq.push({adjnode , dist[adjnode]});
                }
            }
            
        }
        int maxtime=0;
        for(int i=1;i<=n;i++){
            maxtime = max(dist[i] , maxtime);
        }

        if(maxtime==1e9) return -1;
        else return maxtime;
    }
};