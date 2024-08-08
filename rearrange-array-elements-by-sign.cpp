class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        queue<int> pos , neg;
        for(int i=0;i<n;i++){
            if(nums[i]>0) pos.push(nums[i]);
            else neg.push(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(i%2 ==0) {
                nums[i] = pos.front();
                pos.pop();
            }
            else {
                nums[i] = neg.front();
                neg.pop();
            }
            
        }
        return nums;

    }
};