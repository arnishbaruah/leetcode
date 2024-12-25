class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) {
                    cur[buy] = max(ahead[0], -prices[ind] + ahead[1]);
                } else {
                    cur[buy] = max(ahead[1], prices[ind] + ahead[0]);
                }
            }
            ahead = cur;
        }

        return cur[0];
    }
};
