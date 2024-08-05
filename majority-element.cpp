class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it: nums) mpp[it]++;

        for(auto it: nums){
            if(mpp[it] > n/2) return it;
        }
        return -1;
    }
};