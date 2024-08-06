class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        vector<int> ans;
        for(auto it: nums){
            mpp[it]++;
            if(mpp[it] == floor(n/3)+1) ans.push_back(it);
        }
        
        return ans;
        
    }
};