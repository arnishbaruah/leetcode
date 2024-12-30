class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<long> ahead(2, 0);
        vector<long> cur(2, 0);

        long profit;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) {
                    profit = max(0 + ahead[0], -prices[ind] + ahead[1]);
                } else {
                    profit = max(0 + ahead[1], prices[ind] - fee + ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }
        return cur[0];
    }
};
