class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left = 0; //buy
        int right = 1; //sell
        int maxProfit = 0;

        while(right < prices.size()){

            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            }else{
                left = right;
            }

            right++;
        }

        return maxProfit;
        
    }
};
