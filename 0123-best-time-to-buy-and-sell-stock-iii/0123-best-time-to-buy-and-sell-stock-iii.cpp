class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<int> profit(n, 0);
        int maxi = price[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxi = max(maxi, price[i]);
            profit[i] = max(profit[i + 1], maxi - price[i]);
        }
        int mini = price[0];
        for (int i = 1; i < n; i++)
        {
            mini = min(mini, price[i]);
            profit[i] = max(profit[i - 1], profit[i] + (price[i] - mini));
        }
        return profit[n - 1];
    }
};