class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy =0;
        int sell =1;
        int profit = 0;
        int n = prices.size();
        while(sell<n){
            if(prices[buy]<prices[sell]){
                profit = max(profit, prices[sell]-prices[buy]);
            }
            else{
                buy = sell;
            }
            sell++;
        }
// we care about values, not their index difference.
        return profit;
    }
};
