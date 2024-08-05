class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0; // Initialize the variable to store the maximum profit
        int min = prices[0]; // Initialize the minimum price to the first element of the array

        // Iterate through the array of prices
        for (int i = 0; i < prices.size(); i++) {
            // If the current price is less than the minimum price seen so far
            if (prices[i] < min)
                min = prices[i]; // Update the minimum price
            // If the profit from the current price and the minimum price is greater than the maximum profit seen so far
            else if (prices[i] - min > ans) {
                ans = prices[i] - min; // Update the maximum profit
            }
        }

        return ans; // Return the maximum profit
    }
};