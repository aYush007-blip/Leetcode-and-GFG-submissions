class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minprice = INT_MAX;
        int n = prices.size();
        for(int i=0;i<n;i++){
            minprice = min(minprice , prices[i]);
            profit = max(profit, prices[i] - minprice);
        }
        return profit;
    }
};