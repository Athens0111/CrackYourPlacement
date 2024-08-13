class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0; // Initialize the answer (total profit) to 0
        int n = prices.size(); // Get the number of days

        // Iterate through each day, except the last day
        for(int i = 0; i < n - 1; i++) {
            // Check if the price on the next day is higher than the current day
            if(prices[i] < prices[i + 1])
                // If yes, then buy on the current day and sell on the next day,
                // add the difference to the total profit
                ans += (prices[i + 1] - prices[i]);
        }

        return ans; // Return the total profit
    }
};