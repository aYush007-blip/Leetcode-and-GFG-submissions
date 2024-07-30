class Solution {
    private:
    int f(vector<int> num){
        int n = num.size();
        int prev2 = 0, prev1 = num[0];
        for(int i=1;i<n;i++){
            int take = num[i];
            if(i>=2) take+=prev2;
            int notake = prev1;
            int curr = max(take , notake);
            prev2 = prev1;
            prev1=curr;
        }
        return prev1;
    }

    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> t1 , t2;
        for(int i=0;i<n;i++){
            if(i!=0)t1.push_back(nums[i]);
            if(i!=n-1)t2.push_back(nums[i]);
        }
        return max(f(t1) , f(t2));

    }
};