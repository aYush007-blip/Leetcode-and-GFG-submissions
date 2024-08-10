class Solution {
public:
    int bs(vector<int> arr, int start, int target) {
        int end = arr.size()-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]> target) end=mid-1;
            else start = mid+1;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> ans;
        sort(nums.begin() , nums.end());
        for(int i=0;i<nums.size();i++) {
            if(bs(nums, i+1 , nums[i]+k)!=-1)
                ans.insert({nums[i],nums[i]+k});
        }
        return ans.size();
    }
};