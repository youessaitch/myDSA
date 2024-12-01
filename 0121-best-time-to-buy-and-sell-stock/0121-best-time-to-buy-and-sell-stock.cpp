class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int minPrice = 1e9;

        for(int i=0;i<n;i++){
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxi = max(maxi, profit);    
        }

        return maxi;
    }
};