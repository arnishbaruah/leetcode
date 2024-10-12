class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxPro = max(maxPro, profit);
        }

        return maxPro;
    }
};
