class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses] , indegree(numCourses , 0);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        // for(int i=0;i<numCourses;i++){
        //     for(auto it: adj[i]){
        //         indegree[it]++;
        //     }
        // }

        queue<int> q;
       for(int i=0;i<numCourses;i++){
        if(!indegree[i])q.push(i);
       }
        vector<int> topo;

        while(!q.empty()){
            int node  = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it])q.push(it);
            }
        }
        if(topo.size()!= numCourses) return false;
        else return true; 
    }
};