class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({abs(x-arr[i]) , arr[i]});
        }
        vector<int> ans;
        while(k--){
            auto it = pq.top();
            int element = it.second;
            ans.push_back(element);
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};